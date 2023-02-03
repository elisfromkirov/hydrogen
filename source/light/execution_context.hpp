#pragma once

#include <light/landing_pad.hpp>
#include <light/stack.hpp>

#include <light/detail/stack_state.hpp>

namespace light {

class ExecutionContext {
 public:
  ExecutionContext() noexcept;

  ExecutionContext(Stack& stack, ILandingPad* landing_pad) noexcept;

  void SwitchTo(ExecutionContext& context) noexcept;

 private:
  StackState state_;
};

}  // namespace light