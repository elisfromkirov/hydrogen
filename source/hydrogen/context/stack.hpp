#pragma once

#include <crutch/core/core.hpp>

#include <hydrogen/context/detail/stack_base.hpp>

namespace hydrogen {

class Stack final : private detail::StackBase {
 public:
  explicit Stack(crutch::SizeType pages) noexcept;

  [[nodiscard]]
  void* Top() const noexcept;
};

}  // namespace hydrogen