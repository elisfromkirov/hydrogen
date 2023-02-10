#include <hydrogen/fault/std/cond_var.hpp>
#include <hydrogen/fault/std/mutex.hpp>
#include <hydrogen/fault/std/thread.hpp>

#include <hydrogen/fault/test/test_framework.hpp>

#include <iostream>

class WaitGroup {
 public:
  WaitGroup()
      : counter_{0},
        mutex_{},
        work_done_{} {
  }

  void Add(unsigned int count) {
    hydrogen::fault::lock_guard guard{mutex_};
    counter_ += count;
  }

  void Done() {
    hydrogen::fault::lock_guard guard{mutex_};
    counter_ -= 1;
    if (counter_ == 0) {
      work_done_.notify_all();
    }
  }

  void Wait() {
    hydrogen::fault::unique_lock_guard guard{mutex_};
    work_done_.wait(guard, [&]() {
      return counter_ != 0;
    });
  }

 private:
  unsigned int counter_;
  hydrogen::fault::mutex mutex_;
  hydrogen::fault::cond_var work_done_;
};

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
    hydrogen::fault::mutex mutex{};
    crutch::SizeType number{0};

    hydrogen::fault::thread thread_1([&]() {
      for (crutch::SizeType i = 0; i < 100; ++i) {
        {
          hydrogen::fault::lock_guard guard{mutex};
          number += 2;
        }
      }
    });
    hydrogen::fault::thread thread_2([&]() {
      for (crutch::SizeType i = 0; i < 100; ++i) {
        {
          hydrogen::fault::lock_guard guard{mutex};
          number -= 1;
        }
      }
    });

    thread_1.join();
    thread_2.join();

    ASSERT_EQ(number, 100);
  }

  FAULT_TEST(CondVar) {
    WaitGroup wg{};
    wg.Add(2);

    hydrogen::fault::thread thread_1([&]() {
      hydrogen::fault::this_thread::yield();
      wg.Done();
    });

    hydrogen::fault::thread thread_2([&]() {
      hydrogen::fault::this_thread::yield();
      wg.Done();
    });

    wg.Wait();

    thread_1.join();
    thread_2.join();
  }
}

RUN_ALL_SUITES()