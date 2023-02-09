#pragma once

#include <hydrogen/fault/runtime/mutex.hpp>
#include <hydrogen/fault/runtime/wait_queue.hpp>

namespace hydrogen {

namespace fault {

class CondVar {
 public:
  void NotifyOne() noexcept;

  void NotifyAll() noexcept;

  void Wait(Mutex& mutex) noexcept;

 private:
  WaitQueue wait_queue_;
};

}  // namespace fault

}  // namespace hydrogen