#include <hydrogen/fault/mutex.hpp>

#ifdef FAULT_INJECTION

#include <hydrogen/fault/inject/inject.hpp>

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

#else

#endif