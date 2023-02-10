#pragma once

namespace hydrogen {

namespace arch {

class ILandingPad {
 public:
  virtual ~ILandingPad() noexcept = default;

  virtual void Land() = 0;
};

}  // namespace arch

}  // namespace hydrogen