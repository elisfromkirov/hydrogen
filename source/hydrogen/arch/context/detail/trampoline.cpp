#include <hydrogen/arch/context/landing_pad.hpp>

#include <hydrogen/arch/context/detail/trampoline.hpp>

namespace hydrogen {

namespace arch {

namespace detail {

void Trampoline(void*, void*, void*, void*, void*, void*, void* arg) noexcept {
  auto landing_pad = reinterpret_cast<ILandingPad*>(arg);
  landing_pad->Land();
}

}  // namespace detail

}  // namespace arch

}  // namespace hydrogen