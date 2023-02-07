#pragma once

#include <hydrogen/fault/detail/inject/injector.hpp>

#include <atomic>

namespace hydrogen {

namespace detail {

class YieldInjector : public IInjector {
 public:
  static constexpr unsigned int kYieldFrequency = 15;

 public:
  YieldInjector() noexcept;

  void MaybeInject() noexcept override;

 private:
  [[nodiscard]]
  bool NeedInject() const noexcept;

  void Update() noexcept;

  void Reset() noexcept;

  void Inject() noexcept;

 private:
  unsigned int until_yield_;
};

}  // namespace detail

}  // namespace hydrogen