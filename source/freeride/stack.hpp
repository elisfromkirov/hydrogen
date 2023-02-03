#pragma once

#include <freeride/core.hpp>

#include <freeride/detail/stack_base.hpp>

namespace freeride {

class Stack final : private detail::StackBase {
 public:
  Stack(SizeType pages) noexcept;
};

}  // namespace freeride