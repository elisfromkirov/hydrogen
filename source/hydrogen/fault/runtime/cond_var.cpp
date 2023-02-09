#include <hydrogen/fault/runtime/cond_var.hpp>

namespace hydrogen {

namespace fault {

void CondVar::NotifyOne() noexcept {
  wait_queue_.WakeOne();
}

void CondVar::NotifyAll() noexcept {
  wait_queue_.WakeAll();
}

void CondVar::Wait(Mutex& mutex) noexcept {
  mutex.Unlock();
  wait_queue_.Park();
  mutex.Lock();
}

}  // namespace fault

}  // namespace hydrogen