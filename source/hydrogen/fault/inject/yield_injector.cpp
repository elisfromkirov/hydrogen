#include <hydrogen/fault/inject/yield_injector.hpp>

#include <hydrogen/fault/std/thread.hpp>

#include <hydrogen/fault/random/random.hpp>

namespace hydrogen {

namespace fault {

YieldInjector::YieldInjector() noexcept
    : until_yield_{UntilYield()} {
}

void YieldInjector::MaybeInject() noexcept {
  if (NeedInject()) {
    Inject();
  }
}

unsigned int YieldInjector::UntilYield() noexcept {
  return Random() % kYieldFrequency;
}

bool YieldInjector::NeedInject() noexcept {
  if (until_yield_.fetch_sub(1) == 1) {
    until_yield_.store(UntilYield());
    return true;
  }
  return false;
}

void YieldInjector::Inject() noexcept {
  this_thread::yield();
}

}  // namespace fault

}  // namespace hydrogen