#pragma once

#include <hydrogen/fault/detail/std/thread.hpp>
#include <hydrogen/fault/detail/std/wait_queue.hpp>

namespace hydrogen {

namespace detail {

class Scheduler {
 public:
  void Schedule(Thread* thread);

 private:
  WaitQueue run_queue_;
};

}  // namespace detail

}  // namespace hydrogen