#pragma once

#include <freeride/core.hpp>

namespace freeride {

namespace detail {

void* Map(SizeType bytes);

void Unmap(void* data, SizeType bytes);

}  // namespace detail

}  // namespace freeride