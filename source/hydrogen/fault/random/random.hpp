#pragma once

#include <hydrogen/fault/random/get_randomizer.hpp>
#include <hydrogen/fault/random/randomizer.hpp>

namespace hydrogen {

namespace fault {

unsigned int Random(IRandomizer* randomizer = GetRandomizer()) noexcept;

}  // namespace fault

}  // namespace hydrogen