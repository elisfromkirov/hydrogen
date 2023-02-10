#pragma once

#if defined(FAULT_STD)

#include <hydrogen/fault/inject/inject.hpp>

#include <mutex>

namespace hydrogen {

namespace fault {

class mutex {
 public:
  using mutex_impl = ::std::mutex;

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

using lock_guard = ::std::lock_guard<mutex>;

using unique_lock_guard = ::std::unique_lock<mutex>;

}  // namespace fault

}  // namespace hydrogen

#elif defined(FAULT_RUNTIME)

#include <hydrogen/fault/inject/inject.hpp>

#include <hydrogen/fault/runtime/mutex.hpp>

#include <mutex>

namespace hydrogen {

namespace fault {

class mutex {
  friend class cond_var;

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

using lock_guard = ::std::lock_guard<mutex>;

using unique_lock_guard = ::std::unique_lock<mutex>;

}  // namespace fault

}  // namespace hydrogen

#else

#include <mutex>

namespace hydrogen {

namespace fault {

using mutex = ::std::mutex;

using lock_guard = ::std::lock_guard<::std::mutex>;

using unique_lock_guard = ::std::unique_lock<::std::mutex>;

}  // namespace fault

}  // namespace hydrogen

#endif