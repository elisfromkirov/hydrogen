#pragma once

#include <crutch/intrusive/intrusive_list.hpp>

#include <hydrogen/fault/detail/runtime/thread.hpp>

namespace hydrogen {

namespace detail {

class WaitQueue {
 public:
  // put running thread to wait queue
  //  > suspend thread
  //  > switch to scheduler
  void Park() noexcept;

  // put one thread from wait queue to scheduler run queue
  void WakeOne() noexcept;

  // put all threads from wait queue to scheduler run queue
  void WakeAll() noexcept;

 private:
  // precondition: queue non empty
  void Wake() noexcept;

 private:
  crutch::IntrusiveList<Thread> queue_;
};

}  // namespace detail

}  // namespace hydrogen