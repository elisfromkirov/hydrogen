#include <hydrogen/fault/mutex.hpp>

#ifdef FAULT_INJECTION

namespace hydrogen {

namespace fault {

mutex::mutex() noexcept
    : impl_{} {
}

void mutex::lock() {
  Inject();
  impl_.Lock();
  Inject();
}

bool mutex::try_lock() {
  Inject();
  return impl_.TryLock();
}

void mutex::unlock() {
  Inject();
  impl_.Unlock();
  Inject();
}

}  // namespace fault

}  // namespace hydrogen

#endif