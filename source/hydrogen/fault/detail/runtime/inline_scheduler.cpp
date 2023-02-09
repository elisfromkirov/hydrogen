#include <hydrogen/fault/detail/runtime/inline_scheduler.hpp>

namespace hydrogen {

namespace detail {

void InlineScheduler::Schedule(Thread* thread) {
  run_queue_.PushBack(thread);
}

void InlineScheduler::Dispatch() {
  while ((running_thread_ = PickNextThread()) != nullptr) {
    running_thread_->SwitchToThread();
  }
}

Thread* InlineScheduler::RunningThread() {
  return running_thread_;
}

Thread* InlineScheduler::PickNextThread() {
  if (run_queue_.IsEmpty()) {
    return nullptr;
  }
  auto next_thread = run_queue_.Front()->AsValuePtr();
  run_queue_.PopFront();
  return next_thread;
}

}  // namespace detail

}  // namespace hydrogen