#include <hydrogen/context/context.hpp>

#include <hydrogen/context/detail/trampoline.hpp>

namespace hydrogen {

Context::Context() noexcept
    : state_{nullptr} {
}

Context::Context(Stack& stack, ILandingPad* landing_pad) noexcept
    : state_{stack.Top()} {
  SetupStackState(&state_, &detail::Trampoline, landing_pad);
}

void Context::SwitchTo(Context& context) noexcept {
  SwitchStackState(&state_, &context.state_);
}

}  // namespace hydrogen