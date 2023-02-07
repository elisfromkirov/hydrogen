#pragma once

#include <crutch/intrusive/intrusive_list.hpp>

#include <hydrogen/fault/detail/std/thread.hpp>

namespace hydrogen {

namespace detail {

class WaitQueue {
 public:
  void Put(Thread* thread) noexcept;

  Thread* Take() noexcept;

 private:
  crutch::IntrusiveList<Thread> queue_;
};

}  // namespace detail

}  // namespace hydrogen