#pragma once

// Boost activation context implementation
//   https://github.com/boostorg/context/blob/develop/include/boost/context/fiber_ucontext.hpp#L84
//
// TSan fiber libraries support
//    https://github.com/llvm/llvm-project/blob/main/compiler-rt/include/sanitizer/tsan_interface.h#L145
//
// Note: if links are out of date look for functions
//   __tsan_get_current_fiber
//   __tsan_create_fiber
//   __tsan_destroy_fiber
//   __tsan_switch_to_fiber
// in https://github.com/llvm/llvm-project/blob/main/compiler-rt/include/sanitizer/tsan_interface.h
//
// ASan fiber libraries support
//   https://github.com/llvm/llvm-project/blob/main/compiler-rt/include/sanitizer/common_interface_defs.h#L384
//   https://github.com/llvm/llvm-project/blob/main/compiler-rt/include/sanitizer/common_interface_defs.h#L414
//
// Note: if links are out of date look for functions
//   __sanitizer_start_switch_fiber
//   __sanitizer_start_switch_fiber
// in https://github.com/llvm/llvm-project/blob/main/compiler-rt/include/sanitizer/common_interface_defs.h
// or https://github.com/llvm/llvm-project/blob/main/compiler-rt/include/sanitizer/asan_interface.h

#include <hydrogen/arch/context/landing_pad.hpp>
#include <hydrogen/arch/stack/stack.hpp>

#include <hydrogen/arch/context/detail/stack_state.hpp>

namespace hydrogen {

namespace arch {

class Context : private ILandingPad {
 public:
  Context() noexcept;

  Context(Stack& stack, ILandingPad* landing_pad) noexcept;

#if __has_feature(thread_sanitizer)
  ~Context() override;
#endif

  void SwitchTo(Context& context) noexcept;

 private:
  void Land() override;

 private:
  StackState state_;
  ILandingPad* landing_pad_;

 private:
#if __has_feature(address_sanitizer)
  const void* bottom_;
  size_t size_;
#endif

#if __has_feature(thread_sanitizer)
  void* fiber_;
  bool owns_;
#endif
};

}  // namespace arch

}  // namespace hydrogen