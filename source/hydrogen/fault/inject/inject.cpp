#include <hydrogen/fault/inject/inject.hpp>

namespace hydrogen {

namespace fault {

void Inject(IInjector* injector) noexcept {
  injector->MaybeInject();
}

}  // namespace fault

}  // namespace hydrogen