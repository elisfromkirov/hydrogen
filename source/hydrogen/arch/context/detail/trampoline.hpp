#pragma once

namespace hydrogen {

namespace arch {

namespace detail {

void Trampoline(void*, void*, void*, void*, void*, void*, void* arg) noexcept;

}  // namespace arch

}  // namespace detail

}  // namespace hydrogen