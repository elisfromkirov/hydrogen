#include <hydrogen/fault/detail/std/get_scheduler.hpp>
#include <hydrogen/fault/detail/std/thread_asymmetric_transfer.hpp>

namespace hydrogen {

namespace detail {

Thread* ThreadAsymmetricTransfer::RunningThread() noexcept {
  return running_thread_;
}

Thread* ThreadAsymmetricTransfer::running_thread_{nullptr};

ThreadAsymmetricTransfer::ThreadAsymmetricTransfer(Thread* thread)
    : thread_{thread},
      stack_{},
      context_{stack_, thread},
      scheduler_{GetScheduler()},
      scheduler_context_{} {
}

void ThreadAsymmetricTransfer::SwitchToScheduler() noexcept  {
  context_.SwitchTo(scheduler_context_);
  running_thread_ = nullptr;
  scheduler_->Schedule(thread_);
}

void ThreadAsymmetricTransfer::SwitchToThread() noexcept {
  running_thread_ = thread_;
  scheduler_context_.SwitchTo(context_);
}

}  // namespace detail

}  // namespace hydrogen