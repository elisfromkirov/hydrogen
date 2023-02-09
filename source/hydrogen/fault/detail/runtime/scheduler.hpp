#pragma once

namespace hydrogen {

namespace detail {

class Thread;

}  // namespace detail

}  // namespace hydrogen

namespace hydrogen {

namespace detail {

class IScheduler {
 public:
  virtual ~IScheduler() noexcept = default;

  virtual void Schedule(Thread* thread) = 0;

  virtual void Dispatch() = 0;

  virtual Thread* RunningThread() = 0;
};

}  // namespace detail

}  // namespace hydrogen