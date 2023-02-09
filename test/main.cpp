#include <hydrogen/fault/guard.hpp>
#include <hydrogen/fault/mutex.hpp>
#include <hydrogen/fault/thread.hpp>

#include <hydrogen/fault/test/test_framework.hpp>

#include <iostream>

TEST_SUITE(Runtime) {
  FAULT_TEST(Yield) {
    hydrogen::fault::thread thread_1([]() {
      std::cout << "#1" << std::endl;
      hydrogen::fault::this_thread::yield();
      std::cout << "#3" << std::endl;
    });
    hydrogen::fault::thread thread_2([]() {
      std::cout << "#2" << std::endl;
      hydrogen::fault::this_thread::yield();
      std::cout << "#4" << std::endl;
    });
    thread_1.join();
    thread_2.join();
  }

  FAULT_TEST(Mutex) {
    hydrogen::fault::mutex m{};
    crutch::SizeType number{0};

    hydrogen::fault::thread thread_1([&]() {
    for (crutch::SizeType i = 0; i < 100; ++i) {
      {
        hydrogen::fault::lock_guard guard(m);
        number += 2;
        }
      }
    });
    hydrogen::fault::thread thread_2([&]() {
      for (crutch::SizeType i = 0; i < 100; ++i) {
        {
          hydrogen::fault::lock_guard guard(m);
          number -= 1;
        }
      }
    });

    thread_1.join();
    thread_2.join();

    ASSERT_EQ(number, 100);
  }
}

RUN_ALL_SUITES()