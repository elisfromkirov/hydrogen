namespace hydrogen {

namespace fault {

template <typename Thread>
AsymmetricTransfer<Thread>::AsymmetricTransfer() noexcept
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
void AsymmetricTransfer<Thread>::SwitchToThread() {
  scheduler_context_.SwitchTo(context_);
  if (exception_ptr_ != nullptr) {
    ::std::rethrow_exception(exception_ptr_);
  }
}

}  // namespace fault

}  // namespace hydrogen