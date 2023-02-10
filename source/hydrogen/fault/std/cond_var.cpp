#include <hydrogen/fault/std/cond_var.hpp>

#if defined(FAULT_STD)

namespace hydrogen {

namespace fault {

cond_var::cond_var()
    : impl_{} {
}

void cond_var::notify_one() noexcept {
  Inject();
  impl_.notify_one();
  Inject();
}

void cond_var::notify_all() noexcept {
  Inject();
  impl_.notify_all();
  Inject();
}

void cond_var::wait(unique_lock_guard& guard) {
  Inject();
  impl_.wait(guard);
  Inject();
}

}  // namespace fault

}  // namespace hydrogen

#elif defined(FAULT_RUNTIME)

namespace hydrogen {

namespace fault {

cond_var::cond_var()
    : impl_{} {
}

void cond_var::notify_one() noexcept {
  Inject();
  impl_.NotifyOne();
  Inject();
}

void cond_var::notify_all() noexcept {
  Inject();
  impl_.NotifyAll();
  Inject();
}

void cond_var::wait(unique_lock_guard& guard) {
  Inject();
  impl_.Wait(guard.mutex()->impl_);
  Inject();
}

}  // namespace fault

}  // namespace hydrogen

#endif