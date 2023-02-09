#include <crutch/macro/abort.hpp>

#include <hydrogen/fault/runtime/thread.hpp>

namespace hydrogen {

namespace fault {

void Thread::Join() const noexcept {
  while (!done_) {
    Yield();
  }
}

void Thread::Land() {
  try {
    function_();
    done_ = true;
  } catch (...) {
    exception_ptr_ = ::std::current_exception();
  }

  SwitchToScheduler();
}

}  // namespace fault

}  // namespace hydrogen