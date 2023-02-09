#include <hydrogen/fault/cond_var.hpp>

#ifdef FAULT_INJECTION

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