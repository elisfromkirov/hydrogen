#include <hydrogen/fault/detail/std/get_scheduler.hpp>

namespace hydrogen {

namespace detail {

Scheduler* GetScheduler() noexcept {
  static Scheduler scheduler{};
  return &scheduler;
}

}  // namespace detail

}  // namespace hydrogen