#include <hydrogen/arch/stack/detail/mmap.hpp>

#include <sys/mman.h>

namespace hydrogen {

namespace arch {

namespace detail {

void* Map(crutch::SizeType bytes) noexcept {
  return mmap(nullptr, bytes, PROT_READ | PROT_WRITE,
              MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void Unmap(void* data, crutch::SizeType bytes) noexcept {
  munmap(data, bytes);
}

}  // namespace detail

}  // namespace arch

}  // namespace hydrogen