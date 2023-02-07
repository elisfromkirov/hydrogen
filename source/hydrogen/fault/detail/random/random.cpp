#include <hydrogen/fault/detail/random/random.hpp>

namespace hydrogen {

namespace detail {

unsigned int Random(IRandomizer* randomizer) noexcept {
  return randomizer->Generate();
}

}  // namespace detail

}  // namespace hydrogen