#include <hydrogen/fault/runtime/get_scheduler.hpp>
#include <hydrogen/fault/runtime/thread.hpp>
#include <hydrogen/fault/runtime/yield.hpp>

namespace hydrogen {

namespace fault {

void Yield() noexcept {
  auto scheduler = GetScheduler();
  auto running_thread = scheduler->RunningThread();
  scheduler->Schedule(running_thread);
  running_thread->SwitchToScheduler();
}

}  // namespace fault

}  // namespace hydrogen