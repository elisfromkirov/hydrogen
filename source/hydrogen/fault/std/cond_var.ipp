#include <condition_variable>

#ifndef COND_VAR_IMPL
#error Do not include this file directly
#endif

#if defined(FAULT_STD)

namespace hydrogen {

namespace fault {

template <typename Predicate>
void cond_var::wait(unique_lock_guard& guard, Predicate predicate) {
  while (!predicate()) {
    Inject();
    impl_.wait(guard);
    Inject();
  }
}

}  // namespace fault

}  // namespace hydrogen

#elif defined(FAULT_RUNTIME)

namespace hydrogen {

namespace fault {

template <typename Predicate>
void cond_var::wait(unique_lock_guard& guard, Predicate predicate) {
  while (!predicate()) {
    Inject();
    impl_.Wait(guard.mutex()->impl_);
    Inject();
  }
}

}  // namespace fault

}  // namespace hydrogen

#endif