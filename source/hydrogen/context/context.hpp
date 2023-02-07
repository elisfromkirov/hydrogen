#pragma once

#include <hydrogen/context/landing_pad.hpp>
#include <hydrogen/context/stack.hpp>

#include <hydrogen/context/detail/stack_state.hpp>

namespace hydrogen {

class Context {
 public:
  Context() noexcept;

  Context(Stack& stack, ILandingPad* landing_pad) noexcept;

  void SwitchTo(Context& context) noexcept;

 private:
  StackState state_;
};

}  // namespace hydrogen