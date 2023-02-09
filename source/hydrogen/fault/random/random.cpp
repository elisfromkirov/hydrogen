#include <hydrogen/fault/random/random.hpp>

namespace hydrogen {

namespace fault {

unsigned int Random(IRandomizer* randomizer) noexcept {
  return randomizer->Generate();
}

}  // namespace fault

}  // namespace hydrogen