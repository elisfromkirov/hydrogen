#include <hydrogen/arch/stack/stack.hpp>

namespace hydrogen {

namespace arch {

Stack::Stack(crutch::SizeType pages) noexcept
    : detail::StackBase{pages} {
}

crutch::SizeType Stack::Size() const noexcept {
  return bytes_;
}

void* Stack::Data() const noexcept {
  return data_;
}

void* Stack::Bottom() const noexcept {
  return data_;
}

void* Stack::Top() const noexcept {
  return reinterpret_cast<crutch::Byte*>(data_) + bytes_;
}

}  // namespace arch

}  // namespace hydrogen