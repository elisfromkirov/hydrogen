#include <hydrogen/fault/runtime/mutex.hpp>

namespace hydrogen {

namespace fault {

Mutex::Mutex() noexcept
    : locked_{false},
      wait_queue_{} {
}

void Mutex::Lock() noexcept {
  while (locked_) {
    wait_queue_.Park();
  }
  locked_ = true;
}

bool Mutex::TryLock() noexcept {
  return !::std::exchange(locked_, true);
}

void Mutex::Unlock() noexcept {
  locked_ = false;
  wait_queue_.WakeOne();
}

}  // namespace fault

}  // namespace hydrogen