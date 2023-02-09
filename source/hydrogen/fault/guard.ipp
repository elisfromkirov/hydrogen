#ifndef GUARD_IMPL
#error Do not include this file directly
#endif

namespace hydrogen {

namespace fault {

template <typename mutex>
lock_guard<mutex>::lock_guard(mutex& m) : mutex_{m} {
  mutex_.lock();
}

template <typename mutex>
lock_guard<mutex>::~lock_guard() {
  mutex_.unlock();
}

}  // namespace fault

}  // namespace hydrogen