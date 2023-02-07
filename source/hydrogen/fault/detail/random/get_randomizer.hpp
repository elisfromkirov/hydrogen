#pragma once

#include <hydrogen/fault/detail/random/randomizer.hpp>

namespace hydrogen {

namespace detail {

IRandomizer* GetRandomizer() noexcept;

}  // namespace detail

}  // namespace hydrogen