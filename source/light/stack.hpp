#pragma once

#include <light/detail/stack_base.hpp>
#include <light/core.hpp>

namespace light {

class Stack final : private detail::StackBase {
 public:
  explicit Stack(SizeType pages) noexcept;

  [[nodiscard]]
  void* Top() const noexcept;
};

}  // namespace light