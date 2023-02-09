#pragma once

#include <hydrogen/fault/inject/get_injector.hpp>
#include <hydrogen/fault/inject/injector.hpp>

namespace hydrogen {

namespace fault {

void Inject(IInjector* injector = GetInjector()) noexcept;

}  // namespace fault

}  // namespace hydrogen