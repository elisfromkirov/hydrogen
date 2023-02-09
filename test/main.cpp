#include <hydrogen/fault/detail/runtime/get_scheduler.hpp>
#include <hydrogen/fault/detail/runtime/mutex.hpp>
#include <hydrogen/fault/detail/runtime/thread.hpp>

#include <iostream>

using namespace hydrogen::detail;

void YieldExample() {
  std::cout << "yield example" << std::endl;

  Thread main_thread([]() {
    Thread thread_1([]() {
      std::cout << "#1" << std::endl;
      Yield();
      std::cout << "#3" << std::endl;
    });
    Thread thread_2([]() {
      std::cout << "#2" << std::endl;
      Yield();
      std::cout << "#4" << std::endl;
    });
    thread_1.Join();
    thread_2.Join();
  });
  GetScheduler()->Dispatch();

  std::cout << std::endl;
}

void MutexExample() {
  std::cout << "mutex example" << std::endl;

  Thread main_thread([]() {
    Mutex mutex{};
    crutch::SizeType number{0};

    Thread thread_1([&]() {
      for (crutch::SizeType i = 0; i < 100; ++i) {
        mutex.Lock();
        number += 2;
        mutex.Unlock();
      }
    });
    Thread thread_2([&]() {
      for (crutch::SizeType i = 0; i < 100; ++i) {
        mutex.Lock();
        number -= 1;
        mutex.Unlock();
      }
    });

    thread_1.Join();
    thread_2.Join();

    std::cout << std::boolalpha << (number == 100) << std::endl;
  });
  GetScheduler()->Dispatch();

  std::cout << std::endl;
}

int main() {
  YieldExample();
  MutexExample();
  int* a = new int(1);
  a[5] = 1;
  return 0;
}