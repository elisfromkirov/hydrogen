#pragma once

#include <crutch/intrusive/intrusive_list.hpp>

#include <hydrogen/fault/runtime/scheduler.hpp>
#include <hydrogen/fault/runtime/thread.hpp>

namespace hydrogen {

namespace fault {

class InlineScheduler final : public IScheduler {
 public:
  void Schedule(Thread* thread) noexcept override;

  void Dispatch() noexcept override;

  Thread* RunningThread() noexcept override;

 private:
  Thread* PickNextThread() noexcept;

 private:
  Thread* running_thread_;
  ::crutch::IntrusiveList<Thread> run_queue_;
};

}  // namespace fault

}  // namespace hydrogen