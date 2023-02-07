#include <hydrogen/context/detail/mmap.hpp>

#include <sys/mman.h>

namespace hydrogen {

namespace detail {

void* Map(crutch::SizeType bytes) {
  return mmap(nullptr, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void Unmap(void* data, crutch::SizeType bytes) {
  munmap(data, bytes);
}

}  // namespace detail

}  // namespace hydrogen