#pragma once

#ifdef FAULT_INJECTION

#include <crutch/ptr/make_unique_ptr.hpp>
#include <crutch/ptr/unique_ptr.hpp>

#include <hydrogen/fault/runtime/thread.hpp>

namespace hydrogen {

namespace fault {

class thread {
 public:
  using thread_impl = ::crutch::UniquePtr<Thread>;

 public:
  template <typename Function>
  explicit thread(Function&& function);

  void join();

  void swap(thread& other) noexcept;

 private:
  thread_impl impl_;
};

namespace this_thread {

void yield() noexcept;

}  // namespace this_thread

}  // namespace fault

}  // namespace hydrogen

#else

#include <thread>

namespace hydrogen {

namespace fault {

using thread = ::std::thread;

namespace this_thread {

void yield() noexcept;

}  // namespace this_thread

}  // namespace fault

}  // namespace hydrogen

#endif

#define THREAD_IMPL
#include <hydrogen/fault/thread.ipp>
#undef THREAD_IMPL