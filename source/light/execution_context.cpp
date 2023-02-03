#include <light/execution_context.hpp>

#include <light/detail/trampoline.hpp>

namespace light {

ExecutionContext::ExecutionContext() noexcept
    : state_{nullptr} {
}

ExecutionContext::ExecutionContext(Stack& stack, ILandingPad* landing_pad) noexcept
    : state_{stack.Top()} {
  SetupStackState(&state_, &detail::Trampoline, landing_pad);
}

void ExecutionContext::SwitchTo(ExecutionContext& context) noexcept {
  SwitchStackState(&state_, &context.state_);
}

}  // namespace light