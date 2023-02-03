#include <light/execution_context.hpp>
#include <light/landing_pad.hpp>
#include <light/stack.hpp>

#include <iostream>

#include <exception>

class Exception {
 public:
  [[nodiscard]]
  const char* What() const noexcept {
    return "exception";
  }
};

class Routine : private light::ILandingPad {
 public:
  Routine()
      : stack_{16},
        context_{stack_, this},
        external_context_{},
        exception_ptr_{} {
  }

  void Launch() {
    external_context_.SwitchTo(context_);

    if (exception_ptr_ != nullptr) {
      std::rethrow_exception(exception_ptr_);
    }
  }

 private:
  void Land() override {
    try {
      std::cout << "throw an exception" << std::endl;
      throw Exception{};
    } catch (...) {
      exception_ptr_ = std::current_exception();
    }

    context_.SwitchTo(external_context_);
  }

 private:
  light::Stack stack_;
  light::ExecutionContext context_;
  light::ExecutionContext external_context_;
  std::exception_ptr exception_ptr_;
};

int main() {
  Routine routine{};
  try {
    routine.Launch();
  } catch (const Exception& exception) {
    std::cout << exception.What() << std::endl;
  }
  return 0;
}