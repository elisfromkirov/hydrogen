#include <hydrogen/fault/detail/runtime/get_scheduler.hpp>
#include <hydrogen/fault/detail/runtime/thread.hpp>
#include <hydrogen/fault/detail/runtime/yield.hpp>

namespace hydrogen {

namespace detail {

void Yield() {
  auto scheduler = GetScheduler();
  auto running_thread = scheduler->RunningThread();
  scheduler->Schedule(running_thread);
  running_thread->SwitchToScheduler();
}

}  // namespace detail

}  // namespace hydrogen