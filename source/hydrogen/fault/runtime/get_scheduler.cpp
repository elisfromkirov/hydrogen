#include <hydrogen/fault/runtime/get_scheduler.hpp>
#include <hydrogen/fault/runtime/inline_scheduler.hpp>

namespace hydrogen {

namespace fault {

IScheduler* GetScheduler() noexcept {
  static InlineScheduler scheduler{};
  return &scheduler;
}

}  // namespace fault

}  // namespace hydrogen