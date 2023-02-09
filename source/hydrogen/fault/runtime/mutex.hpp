#pragma once

#include <hydrogen/fault/runtime/wait_queue.hpp>

namespace hydrogen {

namespace fault {

class Mutex {
 public:
  Mutex() noexcept;

  void Lock() noexcept;

  bool TryLock() noexcept;

  void Unlock() noexcept;

 private:
  bool locked_;
  WaitQueue wait_queue_;
};

}  // namespace fault

}  // namespace hydrogen