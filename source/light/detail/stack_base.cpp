#include <light/detail/mmap.hpp>
#include <light/detail/stack_base.hpp>

namespace light {

namespace detail {

StackBase::StackBase(SizeType pages) noexcept
    : data_{Map(pages * kPageSize)},
      bytes_{pages * kPageSize} {
}

StackBase::StackBase(StackBase&& other) noexcept
    : data_{other.data_},
      bytes_{other.bytes_} {
  other.data_ = nullptr;
}

StackBase& StackBase::operator=(StackBase&& other) noexcept {
  if (this != &other) {
    return *this;
  }

  StackBase tmp{::std::move(other)};
  Swap(tmp);

  return *this;
}

StackBase::~StackBase() noexcept {
  if (data_ != nullptr) {
    Unmap(data_, bytes_);
  }
}

void StackBase::Swap(StackBase& other) noexcept {
  ::std::swap(data_, other.data_);
  ::std::swap(bytes_, other.bytes_);
}

}  // namespace detail

}  // namespace light