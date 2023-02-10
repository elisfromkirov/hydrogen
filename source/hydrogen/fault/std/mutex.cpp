#include <hydrogen/fault/std/mutex.hpp>

#if defined(FAULT_STD)

namespace hydrogen {

namespace fault {

mutex::mutex() noexcept
    : impl_{} {
}

void mutex::lock() {
  Inject();
  impl_.lock();
  Inject();
}

bool mutex::try_lock() {
  Inject();
  return impl_.try_lock();
}

void mutex::unlock() {
  Inject();
  impl_.unlock();
  Inject();
};

using lock_guard = ::std::lock_guard<mutex>;

using unique_lock_guard = ::std::unique_lock<mutex>;

}  // namespace fault

}  // namespace hydrogen

#elif defined(FAULT_RUNTIME)

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