#pragma once

#include <hydrogen/fault/detail/random/get_randomizer.hpp>
#include <hydrogen/fault/detail/random/randomizer.hpp>

namespace hydrogen {

namespace detail {

unsigned int Random(IRandomizer* randomizer = GetRandomizer()) noexcept;

}  // namespace detail

}  // namespace hydrogen