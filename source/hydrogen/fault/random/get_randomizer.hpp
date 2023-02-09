#pragma once

#include <hydrogen/fault/random/randomizer.hpp>

namespace hydrogen {

namespace fault {

IRandomizer* GetRandomizer() noexcept;

}  // namespace fault

}  // namespace hydrogen