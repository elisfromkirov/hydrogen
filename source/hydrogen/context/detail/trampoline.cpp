#include <hydrogen/context/landing_pad.hpp>

#include <hydrogen/context/detail/trampoline.hpp>

namespace hydrogen {

namespace detail {

void Trampoline(void*, void*, void*, void*, void*, void*, void* argument) {
  auto landing_pad = reinterpret_cast<ILandingPad*>(argument);
  landing_pad->Land();
}

}  // namespace detail

}  // namespace hydrogen