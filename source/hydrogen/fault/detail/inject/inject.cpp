#include <hydrogen/fault/detail/inject/inject.hpp>

namespace hydrogen {

namespace detail {

void Inject(IInjector* injector) noexcept {
  injector->MaybeInject();
}

}  // namespace detail

}  // namespace hydrogen