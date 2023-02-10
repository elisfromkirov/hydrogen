#pragma once

#include <crutch/function/unique_function.hpp>

#include <hydrogen/arch/context/landing_pad.hpp>
#include <hydrogen/arch/context/context.hpp>

#include <hydrogen/arch/stack/stack.hpp>

#include <hydrogen/fault/runtime/get_scheduler.hpp>
#include <hydrogen/fault/runtime/scheduler.hpp>

namespace hydrogen {

namespace fault {

template <typename Thread>
class AsymmetricTransfer {
 public:
  AsymmetricTransfer() noexcept;

  void SwitchToScheduler() noexcept;

  void SwitchToThread();

 protected:
  arch::Stack stack_;
  arch::Context context_;
  IScheduler* scheduler_;
  arch::Context scheduler_context_;
  ::std::exception_ptr exception_ptr_;
};

}  // namespace fault

}  // namespace hydrogen

#include <hydrogen/fault/runtime/asymmetric_transfer.ipp>