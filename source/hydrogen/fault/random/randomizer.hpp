#pragma once

namespace hydrogen {

namespace fault {

class IRandomizer {
 public:
  virtual ~IRandomizer() noexcept = default;

  virtual void Reset(unsigned int seed) noexcept = 0;

  virtual unsigned int Generate() noexcept = 0;
};

}  // namespace fault

}  // namespace hydrogen