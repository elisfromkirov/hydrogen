#include <hydrogen/context/execution_context.hpp>

#include <hydrogen/context/detail/trampoline.hpp>

namespace hydrogen {

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

}  // namespace hydrogen