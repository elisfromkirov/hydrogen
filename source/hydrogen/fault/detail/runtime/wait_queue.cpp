#include <hydrogen/fault/detail/runtime/wait_queue.hpp>

namespace hydrogen {

namespace detail {

void WaitQueue::Park() noexcept {
  auto scheduler = GetScheduler();
  auto running_thread = scheduler->RunningThread();
  queue_.PushBack(running_thread);
  running_thread->SwitchToScheduler();
}

void WaitQueue::WakeOne() noexcept {
  if (!queue_.IsEmpty()) {
    Wake();
  }
}

void WaitQueue::WakeAll() noexcept {
  while (!queue_.IsEmpty()) {
    Wake();
  }
}

void WaitQueue::Wake() noexcept {
  auto thread = queue_.Front()->AsValuePtr();
  queue_.PopFront();
  GetScheduler()->Schedule(thread);
}

}  // namespace detail

}  // namespace hydrogen