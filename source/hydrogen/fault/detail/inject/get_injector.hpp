#pragma once

#include <hydrogen/fault/detail/inject/injector.hpp>

namespace hydrogen {

namespace detail {

IInjector* GetInjector() noexcept;

}  // namespace detail

}  // namespace hydrogen