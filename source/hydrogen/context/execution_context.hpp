#pragma once

#include <hydrogen/context/landing_pad.hpp>
#include <hydrogen/context/stack.hpp>

#include <hydrogen/context/detail/stack_state.hpp>

namespace hydrogen {

class ExecutionContext {
 public:
  ExecutionContext() noexcept;

  ExecutionContext(Stack& stack, ILandingPad* landing_pad) noexcept;

  void SwitchTo(ExecutionContext& context) noexcept;

 private:
  StackState state_;
};

}  // namespace hydrogen