#pragma once

#include <crutch/core/core.hpp>

#include <hydrogen/context/detail/stack_base.hpp>

namespace hydrogen {

class Stack final : private detail::StackBase {
 public:
  static constexpr crutch::SizeType kDefaultPages = 16;

 public:
  explicit Stack(crutch::SizeType pages = kDefaultPages) noexcept;

  [[nodiscard]]
  void* Top() const noexcept;
};

}  // namespace hydrogen