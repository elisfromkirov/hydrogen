#pragma once

#include <hydrogen/fault/std/mutex.hpp>

#if defined(FAULT_STD)

#include <hydrogen/fault/inject/inject.hpp>

#include <condition_variable>

namespace hydrogen {

namespace fault {

class cond_var {
 public:
  using cond_var_impl = ::std::condition_variable_any;

 public:
  cond_var();

  cond_var(const cond_var&) = delete;
  cond_var& operator=(const cond_var&) = delete;

  void notify_one() noexcept;

  void notify_all() noexcept;

  void wait(unique_lock_guard& guard);

  template <typename Predicate>
  void wait(unique_lock_guard& guard, Predicate predicate);

 private:
  cond_var_impl impl_;
};

}  // namespace fault

}  // namespace hydrogen

#elif defined(FAULT_RUNTIME)

#include <hydrogen/fault/inject/inject.hpp>

#include <hydrogen/fault/runtime/cond_var.hpp>

namespace hydrogen {

namespace fault {

class cond_var {
 public:
  using cond_var_impl = CondVar;

 public:
  cond_var();

  cond_var(const cond_var&) = delete;
  cond_var& operator=(const cond_var&) = delete;

  void notify_one() noexcept;

  void notify_all() noexcept;

  void wait(unique_lock_guard& guard);

  template <typename Predicate>
  void wait(unique_lock_guard& guard, Predicate predicate);

 private:
  cond_var_impl impl_;
};

}  // namespace fault

}  // namespace hydrogen

#else

#include <condition_variable>

namespace hydrogen {

namespace fault {

using cond_var = ::std::condition_variable;

}  // namespace fault

}  // namespace hydrogen

#endif

#define COND_VAR_IMPL
#include <hydrogen/fault/std/cond_var.ipp>
#undef COND_VAR_IMPL