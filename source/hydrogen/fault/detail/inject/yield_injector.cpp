#include <hydrogen/fault/thread.hpp>

#include <hydrogen/fault/detail/inject/yield_injector.hpp>

#include <hydrogen/fault/detail/random/random.hpp>

namespace hydrogen {

namespace detail {

YieldInjector::YieldInjector() noexcept
    : until_yield_{0} {
  Reset();
}

void YieldInjector::MaybeInject() noexcept {
  Update();
  if (NeedInject()) {
    Reset();
    Inject();
  }
}

bool YieldInjector::NeedInject() const noexcept {
  return until_yield_ == 0;
}

void YieldInjector::Update() noexcept {
  --until_yield_;
}

void YieldInjector::Reset() noexcept {
  until_yield_ = Random() % yield_frequency;
}

void YieldInjector::Inject() noexcept {
  this_thread::yield();
}

}  // namespace detail

}  // namespace hydrogen