#pragma once

#include <hydrogen/fault/detail/std/scheduler.hpp>

namespace hydrogen {

namespace detail {

Scheduler* GetScheduler() noexcept;

}  // namespace detail

}  // namespace hydrogen