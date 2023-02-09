#pragma once

namespace hydrogen {

namespace fault {

template <typename mutex>
class lock_guard final {
 public:
  explicit lock_guard(mutex& m);

  lock_guard(const lock_guard&) = delete;
  lock_guard& operator=(const lock_guard&) = delete;

  ~lock_guard();

 private:
  mutex& mutex_;
};

template<typename mutex>
lock_guard(mutex&) -> lock_guard<mutex>;

}  // namespace fault

}  // namespace hydrogen

#define GUARD_IMPL
#include <hydrogen/fault/guard.ipp>
#undef GUARD_IMPL