#pragma once

namespace hydrogen {

namespace fault {

class Thread;

}  // namespace fault

}  // namespace hydrogen

namespace hydrogen {

namespace fault {

class IScheduler {
 public:
  virtual ~IScheduler() noexcept = default;

  virtual void Schedule(Thread* thread) noexcept = 0;

  virtual void Dispatch() noexcept = 0;

  virtual Thread* RunningThread() noexcept = 0;
};

}  // namespace fault

}  // namespace hydrogen