#include <hydrogen/fault/detail/random/get_randomizer.hpp>
#include <hydrogen/fault/detail/random/mersenne_randomizer.hpp>

namespace hydrogen {

namespace detail {

IRandomizer* GetRandomizer() noexcept {
  static MersenneRandomizer randomizer{};
  return &randomizer;
}

}  // namespace detail

}  // namespace hydrogen