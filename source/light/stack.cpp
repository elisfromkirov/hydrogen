#include <light/stack.hpp>

namespace light {

Stack::Stack(SizeType pages) noexcept
    : detail::StackBase{pages} {
}

void* Stack::Top() const noexcept {
  return reinterpret_cast<Byte*>(data_) + bytes_;
}

}  // namespace light