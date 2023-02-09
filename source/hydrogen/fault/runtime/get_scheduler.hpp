#pragma once

#include <hydrogen/fault/runtime/scheduler.hpp>

namespace hydrogen {

namespace fault {

IScheduler* GetScheduler() noexcept;

}  // namespace fault

}  // namespace hydrogen