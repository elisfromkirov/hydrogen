#include <light/detail/mmap.hpp>

#include <sys/mman.h>

namespace light {

namespace detail {

void* Map(SizeType bytes) {
  return mmap(nullptr, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void Unmap(void* data, SizeType bytes) {
  munmap(data, bytes);
}

}  // namespace detail

}  // namespace light