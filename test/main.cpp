#include <hydrogen/fault/runtime/get_scheduler.hpp>
#include <hydrogen/fault/runtime/mutex.hpp>
#include <hydrogen/fault/runtime/thread.hpp>

#include <hydrogen/fault/thread.hpp>

#include <iostream>

using namespace hydrogen::fault;

void MoveExample() {
  std::cout << "move example" << std::endl;

  thread main_thread([]() {
    std::cout << "hello from";

    thread nested_thread([]() {
      std::cout << " main ";
      this_thread::yield();
      std::cout << "thread";
    });

    thread moved_nested_thread = std::move(nested_thread);

    moved_nested_thread.join();
  });

  thread moved_main_tread = std::move(main_thread);

  GetScheduler()->Dispatch();

  std::cout << std::endl;
}

void SwapExample() {
  std::cout << "swap example" << std::endl;

  thread main_thread([]() {
    thread thread_1([]() {
      std::cout << "#1" << std::endl;
      this_thread::yield();
      std::cout << "#3" << std::endl;
    });
    thread thread_2([]() {
      std::cout << "#2" << std::endl;
      this_thread::yield();
      std::cout << "#4" << std::endl;
    });

    thread_1.swap(thread_2);

    thread_1.join();
    thread_2.join();
  });

  GetScheduler()->Dispatch();

  std::cout << std::endl;
}

void YieldExample() {
  std::cout << "yield example" << std::endl;

  thread main_thread([]() {
    thread thread_1([]() {
      std::cout << "#1" << std::endl;
      this_thread::yield();
      std::cout << "#3" << std::endl;
    });
    thread thread_2([]() {
      std::cout << "#2" << std::endl;
      this_thread::yield();
      std::cout << "#4" << std::endl;
    });
    thread_1.join();
    thread_2.join();
  });

  GetScheduler()->Dispatch();

  std::cout << std::endl;
}

void MutexExample() {
  std::cout << "mutex example" << std::endl;

  thread main_thread([]() {
    Mutex mutex{};
    crutch::SizeType number{0};

    thread thread_1([&]() {
      for (crutch::SizeType i = 0; i < 100; ++i) {
        mutex.Lock();
        number += 2;
        mutex.Unlock();
      }
    });
    thread thread_2([&]() {
      for (crutch::SizeType i = 0; i < 100; ++i) {
        mutex.Lock();
        number -= 1;
        mutex.Unlock();
      }
    });

    thread_1.join();
    thread_2.join();

    std::cout << std::boolalpha << (number == 100) << std::endl;
  });

  GetScheduler()->Dispatch();

  std::cout << std::endl;
}

int main() {
  MoveExample();
  SwapExample();
  YieldExample();
  MutexExample();
  return 0;
}