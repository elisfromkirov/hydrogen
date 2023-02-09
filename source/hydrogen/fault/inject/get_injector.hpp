#pragma once

#include <hydrogen/fault/inject/injector.hpp>

namespace hydrogen {

namespace fault {

IInjector* GetInjector() noexcept;

}  // namespace fault

}  // namespace hydrogen