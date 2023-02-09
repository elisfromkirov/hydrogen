#pragma once

#include <crutch/intrusive/intrusive_node.hpp>

#include <hydrogen/fault/detail/runtime/asymmetric_transfer.hpp>
#include <hydrogen/fault/detail/runtime/yield.hpp>

namespace hydrogen {

namespace detail {

class Thread final : public ::crutch::IntrusiveNode<Thread>,
                     public AsymmetricTransfer<Thread>,
                     public ILandingPad {
 public:
  template <typename Function>
  explicit Thread(Function&& function);

  Thread(Thread&& other) noexcept = default;
  Thread& operator=(Thread&& other) noexcept = default;

  void Join();

  void Land() override;

 private:
  ::crutch::UniqueFunction<void()> function_;
  bool done_;
};

}  // namespace detail

}  // namespace hydrogen

#define THREAD_IMPL
#include <hydrogen/fault/detail/runtime/thread.ipp>
#undef THREAD_IMPL