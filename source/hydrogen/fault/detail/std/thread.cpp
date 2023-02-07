#include <crutch/macro/abort.hpp>

#include <hydrogen/fault/detail/std/thread.hpp>

namespace hydrogen {

namespace detail {

void Thread::Join() {
  while (!done_) {
    // backoff
  }
}

bool Thread::Done() const noexcept {
  return done_;
}

void Thread::Land() {
  try {
    function_();
  } catch (...) {
    ABORT();
  }

  SwitchToScheduler();
}

}  // namespace detail

}  // namespace hydrogen