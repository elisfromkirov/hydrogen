#include <hydrogen/fault/detail/std/scheduler.hpp>

namespace hydrogen {

namespace detail {

void Scheduler::Schedule(Thread* thread) {
  if (!thread->Done()) {
    run_queue_.Put(thread);
  }

  if (ThreadAsymmetricTransfer::RunningThread() == nullptr) {
    thread = run_queue_.Take();
    thread->SwitchToThread();
  }
}

}  // namespace detail

}  // namespace hydrogen