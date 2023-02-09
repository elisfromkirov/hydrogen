#pragma once

#include <hydrogen/fault/detail/runtime/scheduler.hpp>

namespace hydrogen {

namespace detail {

IScheduler* GetScheduler() noexcept;

}  // namespace detail

}  // namespace hydrogen