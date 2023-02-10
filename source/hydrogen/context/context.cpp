#include <hydrogen/context/context.hpp>

#include <hydrogen/context/detail/trampoline.hpp>

#if __has_feature(address_sanitizer)
#include <sanitizer/asan_interface.h>
#endif

#if __has_feature(thread_sanitizer)
#include <sanitizer/tsan_interface.h>
#endif

namespace hydrogen {

Context::Context() noexcept
    : state_{nullptr},
      landing_pad_{nullptr} {
#if __has_feature(address_sanitizer)
  bottom_ = nullptr;
  size_ = 0;
#endif

#if __has_feature(thread_sanitizer)
  fiber_ = __tsan_get_current_fiber();
  owns_ = false;
#endif
}

Context::Context(Stack& stack, ILandingPad* landing_pad) noexcept
    : state_{stack.Top()},
      landing_pad_{landing_pad} {
#if __has_feature(address_sanitizer)
  bottom_ = stack.Bottom();
  size_ = stack.Size();
#endif

#if __has_feature(thread_sanitizer)
  fiber_ = __tsan_create_fiber(0);
  owns_ = true;
#endif

  SetupStackState(&state_, &detail::Trampoline, this);
}

#if __has_feature(thread_sanitizer)
Context::~Context() noexcept {
  if (owns_) {
    __tsan_destroy_fiber(fiber_);
  }
}
#endif

#if __has_feature(address_sanitizer)
static thread_local Context* from = nullptr;
#endif

void Context::SwitchTo(Context& context) noexcept {
#if __has_feature(address_sanitizer)
  from = this;
#endif

#if __has_feature(address_sanitizer)
  __sanitizer_start_switch_fiber(nullptr, context.bottom_, context.size_);
#endif

#if __has_feature(thread_sanitizer)
  __tsan_switch_to_fiber(fiber_, 0);
#endif

  SwitchStackState(&state_, &context.state_);

#if __has_feature(address_sanitizer)
  __sanitizer_finish_switch_fiber(nullptr, &from->bottom_, &from->size_);
#endif
}

void Context::Land() {
#if __has_feature(address_sanitizer)
  __sanitizer_finish_switch_fiber(nullptr, &from->bottom_, &from->size_);
#endif

  landing_pad_->Land();
}

}  // namespace hydrogen