#pragma once

#include <crutch/function/unique_function.hpp>

#include <hydrogen/context/landing_pad.hpp>
#include <hydrogen/context/stack.hpp>
#include <hydrogen/context/context.hpp>

namespace hydrogen {

namespace detail {

class Thread;
class Scheduler;

}  // namespace detail

}  // namespace hydrogen

namespace hydrogen {

namespace detail {

class ThreadAsymmetricTransfer {
 public:
  static Thread* RunningThread() noexcept;

 private:
  static Thread* running_thread_;

 public:
  explicit ThreadAsymmetricTransfer(Thread* thread);

  void SwitchToScheduler() noexcept;

  void SwitchToThread() noexcept;

 protected:
  Thread* thread_;
  Stack stack_;
  Context context_;
  Scheduler* scheduler_;
  Context scheduler_context_;
};

}  // namespace detail

}  // namespace hydrogen