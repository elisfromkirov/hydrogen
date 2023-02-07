#include <hydrogen/fault/thread.hpp>

namespace hydrogen {

namespace this_thread {

void yield() noexcept {
  ::std::this_thread::yield();
}

}  // namespace this_thread

}  // namespace hydrogen