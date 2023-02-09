#pragma once

#include <crutch/core/core.hpp>

namespace hydrogen {

namespace detail {

void* Map(crutch::SizeType bytes) noexcept;

void Unmap(void* data, crutch::SizeType bytes) noexcept;

}  // namespace detail

}  // namespace hydrogen