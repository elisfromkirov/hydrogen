#include <light/execution_context.hpp>
#include <light/landing_pad.hpp>
#include <light/stack.hpp>

#include <iostream>
#include <functional>

class Routine : private light::ILandingPad {
 public:
  Routine()
      : stack_{16},
        context_{stack_, this},
        external_context_{} {
  }

  void Launch() {
    external_context_.SwitchTo(context_);
  }

 private:
  void Land() override {
    std::cout << __func__ << std::endl;
    context_.SwitchTo(external_context_);
    std::cout << __func__ << std::endl;
    context_.SwitchTo(external_context_);
  }

 private:
  light::Stack stack_;
  light::ExecutionContext context_;
  light::ExecutionContext external_context_;
};

int main() {
  Routine routine{};
  std::cout << __func__ << std::endl;
  routine.Launch();
  std::cout << __func__ << std::endl;
  routine.Launch();
  std::cout << __func__ << std::endl;
  return 0;
}