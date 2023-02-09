#pragma once

#include <random>
#include <hydrogen/fault/random/randomizer.hpp>

namespace hydrogen {

namespace fault {

class MersenneRandomizer final : public IRandomizer {
 public:
  void Reset(unsigned int seed) noexcept override;

  unsigned int Generate() noexcept override;

 private:
  ::std::mt19937 impl_;
};

}  // namespace fault

}  // namespace hydrogen