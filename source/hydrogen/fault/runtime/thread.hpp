#pragma once

#include <crutch/intrusive/intrusive_node.hpp>

#include <hydrogen/fault/runtime/asymmetric_transfer.hpp>
#include <hydrogen/fault/runtime/yield.hpp>

namespace hydrogen {

namespace fault {

class Thread final : public crutch::IntrusiveNode<Thread>,
                     public AsymmetricTransfer<Thread>,
                     public arch::ILandingPad {
 public:
  template <typename Function>
  explicit Thread(Function&& function);

  void Join() const noexcept;

  void Land() override;

 private:
  crutch::UniqueFunction<void()> function_;
  bool done_;
};

}  // namespace fault

}  // namespace hydrogen

#define THREAD_IMPL
#include <hydrogen/fault/runtime/thread.ipp>
#undef THREAD_IMPL