#include <hydrogen/fault/runtime/inline_scheduler.hpp>

namespace hydrogen {

namespace fault {

void InlineScheduler::Schedule(Thread* thread) noexcept {
  run_queue_.PushBack(thread);
}

void InlineScheduler::Dispatch() {
  while ((running_thread_ = PickNextThread()) != nullptr) {
    running_thread_->SwitchToThread();
  }
}

Thread* InlineScheduler::RunningThread() noexcept {
  return running_thread_;
}

Thread* InlineScheduler::PickNextThread() noexcept {
  if (run_queue_.IsEmpty()) {
    return nullptr;
  }
  auto next_thread = run_queue_.Front()->AsValuePtr();
  run_queue_.PopFront();
  return next_thread;
}

}  // namespace fault

}  // namespace hydrogen