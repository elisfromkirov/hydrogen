#pragma once

namespace light {

class ILandingPad {
 public:
  virtual ~ILandingPad() noexcept = default;

  virtual void Land() = 0;
};

}  // namespace light