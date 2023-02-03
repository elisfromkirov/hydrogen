#pragma once

#include <light/core.hpp>

namespace light {

namespace detail {

void* Map(SizeType bytes);

void Unmap(void* data, SizeType bytes);

}  // namespace detail

}  // namespace light