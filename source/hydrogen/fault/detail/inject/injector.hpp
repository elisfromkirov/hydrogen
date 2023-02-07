#pragma once

namespace hydrogen {

namespace detail {

class IInjector {
 public:
  virtual ~IInjector() noexcept = default;

  virtual void MaybeInject() noexcept = 0;
};

}  // namespace detail

}  // namespace hydrogen