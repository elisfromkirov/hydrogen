#include <freeride/detail/mmap.hpp>

#include <sys/mman.h>

namespace freeride {

namespace detail {

void* Map(SizeType bytes) {
  return mmap(nullptr, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE, 0, 0);
}

void Unmap(void* data, SizeType bytes) {
  munmap(data, bytes);
}

}  // namespace detail

}  // namespace freeride