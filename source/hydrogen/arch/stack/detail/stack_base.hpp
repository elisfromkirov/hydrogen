#pragma once

#include <crutch/core/core.hpp>

namespace hydrogen {

namespace arch {

namespace detail {

class StackBase {
 public:
  static constexpr crutch::SizeType kPageSize = 4096;

 public:
  explicit StackBase(crutch::SizeType pages) noexcept;

  StackBase(const StackBase& other) = delete;
  StackBase& operator=(const StackBase& other) = delete;

  StackBase(StackBase&& other) noexcept;
  StackBase& operator=(StackBase&& other) noexcept;

 protected:
  ~StackBase() noexcept;

  void Swap(StackBase& other) noexcept;

 protected:
  void* data_;
  crutch::SizeType bytes_;
};

}  // namespace detail

}  // namespace arch

}  // namespace hydrogen