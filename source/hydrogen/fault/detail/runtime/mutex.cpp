#include <hydrogen/fault/detail/runtime/get_scheduler.hpp>
#include <hydrogen/fault/detail/runtime/mutex.hpp>

namespace hydrogen {

namespace detail {

Mutex::Mutex()
    : locked_{false},
      wait_queue_{} {
}

void Mutex::Lock() {
  while (locked_) {
    wait_queue_.Park();
  }
  locked_ = true;
}

void Mutex::Unlock() {
  locked_ = false;
  wait_queue_.WakeOne();
}

}  // namespace detail

}  // namespace hydrogen