#pragma once

#include <crutch/core/core.hpp>

#include <hydrogen/arch/stack/detail/stack_base.hpp>

namespace hydrogen {

namespace arch {

class Stack final : private detail::StackBase {
 public:
  static constexpr crutch::SizeType kDefaultPages = 16;

 public:
  explicit Stack(crutch::SizeType pages = kDefaultPages) noexcept;

  [[nodiscard]] crutch::SizeType Size() const noexcept;

  [[nodiscard]] void* Data() const noexcept;

  [[nodiscard]] void* Bottom() const noexcept;

  [[nodiscard]] void* Top() const noexcept;
};

}  // namespace arch

}  // namespace hydrogen