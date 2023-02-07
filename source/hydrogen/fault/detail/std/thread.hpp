#pragma once

#include <crutch/intrusive/intrusive_node.hpp>

#include <hydrogen/fault/detail/std/thread_asymmetric_transfer.hpp>

namespace hydrogen {

namespace detail {

class Thread final : public crutch::IntrusiveNode<Thread>,
                     public ThreadAsymmetricTransfer,
                     public ILandingPad {
 public:
  // TODO: Constructor

  Thread(const Thread& other) = delete;
  Thread& operator=(const Thread& other) = delete;

  void Join();

  [[nodiscard]]
  bool Done() const noexcept;

  void Land() override;

 private:
  crutch::UniqueFunction<void()> function_;
  bool done_;
};

}  // namespace detail

}  // namespace hydrogen