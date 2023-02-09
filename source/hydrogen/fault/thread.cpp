#include <hydrogen/fault/thread.hpp>

#ifdef FAULT_INJECTION

namespace hydrogen {

namespace fault {

void thread::join() {
  impl_->Join();
}

void thread::swap(thread& other) noexcept {
  impl_.Swap(other.impl_);
}

namespace this_thread {

void yield() noexcept {
  Yield();
}

}  // namespace this_thread

}  // namespace fault

}  // namespace hydrogen

#else

namespace hydrogen {

namespace fault {

namespace this_thread {

void yield() noexcept {
  ::std::this_thread::yield();
}

}  // namespace this_thread

}  // namespace fault

}  // namespace hydrogen

#endif