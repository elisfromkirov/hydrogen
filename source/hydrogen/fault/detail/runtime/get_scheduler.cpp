#include <hydrogen/fault/detail/runtime/get_scheduler.hpp>
#include <hydrogen/fault/detail/runtime/inline_scheduler.hpp>

namespace hydrogen {

namespace detail {

IScheduler* GetScheduler() noexcept {
  static InlineScheduler scheduler{};
  return &scheduler;
}

}  // namespace detail

}  // namespace hydrogen