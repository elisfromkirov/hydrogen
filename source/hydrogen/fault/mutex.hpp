#pragma once

#ifdef FAULT_INJECTION

#include <hydrogen/fault/runtime/mutex.hpp>

namespace hydrogen {

namespace fault {

class mutex {
 public:
  using mutex_impl = Mutex;

 public:
  mutex() noexcept;

  mutex(const mutex&) = delete;
  mutex& operator=(const mutex&) = delete;

  void lock();

  bool try_lock();

  void unlock();

 private:
  mutex_impl impl_;
};

}  // namespace fault

}  // namespace hydrogen

#else

#include <mutex>

namespace hydrogen {

namespace fault {

using mutex = ::std::mutex;

}  // namespace fault

}  // namespace hydrogen

#endif