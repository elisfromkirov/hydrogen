#pragma once

#include <hydrogen/fault/detail/inject/get_injector.hpp>
#include <hydrogen/fault/detail/inject/injector.hpp>

namespace hydrogen {

namespace detail {

void Inject(IInjector* injector = GetInjector()) noexcept;

}  // namespace detail

}  // namespace hydrogen