#pragma once

namespace hydrogen {

namespace fault {

class IInjector {
 public:
  virtual ~IInjector() noexcept = default;

  virtual void MaybeInject() noexcept = 0;
};

}  // namespace fault

}  // namespace hydrogen