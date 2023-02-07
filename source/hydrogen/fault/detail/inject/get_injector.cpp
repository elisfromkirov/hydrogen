#include <hydrogen/fault/detail/inject/get_injector.hpp>
#include <hydrogen/fault/detail/inject/yield_injector.hpp>

namespace hydrogen {

namespace detail {

IInjector* GetInjector() noexcept {
  static YieldInjector injector{};
  return &injector;
}

}  // namespace detail

}  // namespace hydrogen