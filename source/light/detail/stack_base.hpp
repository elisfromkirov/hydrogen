#pragma once

#include <light/core.hpp>

namespace light {

namespace detail {

class StackBase {
 public:
  static constexpr SizeType kPageSize = 4096;

 public:
  explicit StackBase(SizeType pages) noexcept;

  StackBase(const StackBase& other) = delete;
  StackBase& operator=(const StackBase& other) = delete;

  StackBase(StackBase&& other) noexcept;
  StackBase& operator=(StackBase&& other) noexcept;

 protected:
  ~StackBase() noexcept;

  void Swap(StackBase& other) noexcept;

 protected:
  void* data_;
  SizeType bytes_;
};

}  // namespace detail

}  // namespace light