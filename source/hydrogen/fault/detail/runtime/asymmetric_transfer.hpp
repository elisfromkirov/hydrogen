#pragma once

#include <crutch/function/unique_function.hpp>

#include <hydrogen/context/landing_pad.hpp>
#include <hydrogen/context/stack.hpp>
#include <hydrogen/context/context.hpp>

#include <hydrogen/fault/detail/runtime/get_scheduler.hpp>
#include <hydrogen/fault/detail/runtime/scheduler.hpp>

namespace hydrogen {

namespace detail {

template <typename Thread>
class AsymmetricTransfer {
 public:
  AsymmetricTransfer();

  void SwitchToScheduler() noexcept;

  void SwitchToThread() noexcept;

 protected:
  Stack stack_;
  Context context_;
  IScheduler* scheduler_;
  Context scheduler_context_;
};

}  // namespace detail

}  // namespace hydrogen

#include <hydrogen/fault/detail/runtime/asymmetric_transfer.ipp>