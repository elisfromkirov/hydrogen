#ifndef THREAD_IMPL
#error Do not include this file directly
#endif

namespace hydrogen {

namespace fault {

template <typename Function>
Thread::Thread(Function&& function)
    : crutch::IntrusiveNode<Thread>{},
      AsymmetricTransfer<Thread>{},
      function_{std::forward<Function>(function)},
      done_{false} {
  scheduler_->Schedule(this);
}

}  // namespace fault

}  // namespace hydrogen