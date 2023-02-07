#pragma once

namespace hydrogen {

namespace detail {

class IRandomizer {
 public:
  virtual ~IRandomizer() noexcept = default;

  virtual void Reset(unsigned int seed) noexcept = 0;

  virtual unsigned int Generate() noexcept = 0;
};

}  // namespace detail

}  // namespace hydrogen