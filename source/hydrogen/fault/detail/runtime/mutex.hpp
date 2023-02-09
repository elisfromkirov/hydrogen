#pragma once

#include <hydrogen/fault/detail/runtime/wait_queue.hpp>

namespace hydrogen {

namespace detail {

class Mutex {
 public:
  Mutex();

  void Lock();

  void Unlock();

 private:
  bool locked_;
  WaitQueue wait_queue_;
};

}  // namespace detail

}  // namespace hydrogen