#pragma once

namespace hydrogen {

class ILandingPad {
 public:
  virtual ~ILandingPad() noexcept = default;

  virtual void Land() = 0;
};

}  // namespace hydrogen