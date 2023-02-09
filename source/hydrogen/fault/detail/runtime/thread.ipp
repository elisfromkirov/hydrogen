#ifndef THREAD_IMPL
#error Do not include this file directly
#endif

namespace hydrogen {

namespace detail {

template <typename Function>
Thread::Thread(Function&& function)
    : ::crutch::IntrusiveNode<Thread>{},
      AsymmetricTransfer<Thread>{},
      function_{std::forward<Function>(function)},
      done_{false} {
  scheduler_->Schedule(this);
}

}  // namespace detail

}  // namespace hydrogen