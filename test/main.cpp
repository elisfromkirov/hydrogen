#include <hydrogen/fault/detail/runtime/get_scheduler.hpp>
#include <hydrogen/fault/detail/runtime/thread.hpp>

#include <iostream>

using namespace hydrogen::detail;

int main() {
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
  return 0;
}