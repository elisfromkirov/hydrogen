#include <crutch/macro/abort.hpp>

#include <hydrogen/fault/detail/runtime/thread.hpp>

namespace hydrogen {

namespace detail {

void Thread::Join() {
  while (!done_) {
    Yield();
  }
}

void Thread::Land() {
  try {
    function_();
    done_ = true;
  } catch (...) {
    ABORT();
  }

  SwitchToScheduler();
}

}  // namespace detail

}  // namespace hydrogen