#pragma once

#include <crutch/core/core.hpp>

namespace hydrogen {

namespace detail {

void* Map(crutch::SizeType bytes);

void Unmap(void* data, crutch::SizeType bytes);

}  // namespace detail

}  // namespace hydrogen