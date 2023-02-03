#include <light/landing_pad.hpp>

#include <light/detail/trampoline.hpp>

namespace light {

namespace detail {

void Trampoline(void*, void*, void*, void*, void*, void*, void* argument) {
  ILandingPad* landing_pad = reinterpret_cast<ILandingPad*>(argument);
  landing_pad->Land();
}

}  // namespace detail

}  // namespace light