#include <hydrogen/fault/random/get_randomizer.hpp>
#include <hydrogen/fault/random/mersenne_randomizer.hpp>

namespace hydrogen {

namespace fault {

IRandomizer* GetRandomizer() noexcept {
  static MersenneRandomizer randomizer{};
  return &randomizer;
}

}  // namespace fault

}  // namespace hydrogen