#include "stack.hpp"

namespace hydrogen {

Stack::Stack(crutch::SizeType pages) noexcept
    : detail::StackBase{pages} {
}

void* Stack::Top() const noexcept {
  return reinterpret_cast<crutch::Byte*>(data_) + bytes_;
}

}  // namespace context