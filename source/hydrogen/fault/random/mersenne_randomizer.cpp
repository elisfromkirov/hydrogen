#include <hydrogen/fault/random/mersenne_randomizer.hpp>

namespace hydrogen {

namespace fault {

void MersenneRandomizer::Reset(unsigned int seed) noexcept {
  impl_.seed(reinterpret_cast<::std::mt19937::result_type>(seed));
}

unsigned int MersenneRandomizer::Generate() noexcept {
  return reinterpret_cast<::std::mt19937::result_type>(impl_());
}

}  // namespace fault

}  // namespace hydrogen