#include <hydrogen/fault/inject/get_injector.hpp>
#include <hydrogen/fault/inject/yield_injector.hpp>

namespace hydrogen {

namespace fault {

IInjector* GetInjector() noexcept {
  static YieldInjector injector{};
  return &injector;
}

}  // namespace fault

}  // namespace hydrogen