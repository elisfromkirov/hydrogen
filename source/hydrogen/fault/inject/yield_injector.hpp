#pragma once

#include <hydrogen/fault/inject/injector.hpp>

#include <atomic>

namespace hydrogen {

namespace fault {

class YieldInjector final : public IInjector {
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

}  // namespace fault

}  // namespace hydrogen