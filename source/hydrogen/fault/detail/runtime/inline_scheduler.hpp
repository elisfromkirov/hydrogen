#pragma once

#include <crutch/intrusive/intrusive_list.hpp>

#include <hydrogen/fault/detail/runtime/scheduler.hpp>
#include <hydrogen/fault/detail/runtime/thread.hpp>

namespace hydrogen {

namespace detail {

class InlineScheduler final : public IScheduler {
 public:
  void Schedule(Thread* thread) override;

  void Dispatch() override;

  Thread* RunningThread() override;

 private:
  Thread* PickNextThread();

 private:
  Thread* running_thread_;
  ::crutch::IntrusiveList<Thread> run_queue_;
};

}  // namespace detail

}  // namespace hydrogen