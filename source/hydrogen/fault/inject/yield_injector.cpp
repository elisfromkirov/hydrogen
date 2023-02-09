#include <hydrogen/fault/thread.hpp>

#include <hydrogen/fault/inject/yield_injector.hpp>

#include <hydrogen/fault/random/random.hpp>

namespace hydrogen {

namespace fault {

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
  until_yield_ = Random() % kYieldFrequency;
}

void YieldInjector::Inject() noexcept {
  this_thread::yield();
}

}  // namespace fault

}  // namespace hydrogen