namespace hydrogen {

namespace detail {

template <typename Thread>
AsymmetricTransfer<Thread>::AsymmetricTransfer()
    : stack_{},
      context_{stack_, static_cast<Thread*>(this)},
      scheduler_{GetScheduler()},
      scheduler_context_{} {
}

template <typename Thread>
void AsymmetricTransfer<Thread>::SwitchToScheduler() noexcept  {
  context_.SwitchTo(scheduler_context_);
}

template <typename Thread>
void AsymmetricTransfer<Thread>::SwitchToThread() noexcept {
  scheduler_context_.SwitchTo(context_);
}

}  // namespace detail

}  // namespace hydrogen