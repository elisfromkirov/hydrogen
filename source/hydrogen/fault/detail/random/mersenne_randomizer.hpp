#pragma once

#include <random>
#include <hydrogen/fault/detail/random/randomizer.hpp>

namespace hydrogen {

namespace detail {

class MersenneRandomizer : public IRandomizer {
 public:
  void Reset(unsigned int seed) noexcept override;

  unsigned int Generate() noexcept override;

 private:
  ::std::mt19937 impl_;
};

}  // namespace detail

}  // namespace hydrogen