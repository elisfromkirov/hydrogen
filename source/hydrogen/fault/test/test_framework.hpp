#pragma once

#include <crutch/string/string_view.hpp>

#include <crutch/test/test_framework.hpp>

#if defined(FAULT_RUNTIME)

#include <hydrogen/fault/runtime/get_scheduler.hpp>
#include <hydrogen/fault/runtime/thread.hpp>

#define FAULT_TEST_IMPL(TestRoutine, Test, name, kTestFactory) \
  void TestRoutine();                                          \
                                                               \
  class Test : public ::crutch::ITest {                        \
   public:                                                     \
    ::crutch::StringView Name() const noexcept override {      \
      return ::crutch::StringView{name};                       \
    }                                                          \
                                                               \
    ::crutch::StringView Suite() const noexcept override {     \
      return kSuite.Name();                                    \
    }                                                          \
                                                               \
    void Run() override {                                      \
      ::hydrogen::fault::Thread main_thread{[]() {             \
        TestRoutine();                                         \
      }};                                                      \
      ::hydrogen::fault::GetScheduler()->Dispatch();           \
    }                                                          \
  };                                                           \
                                                               \
  static ::crutch::TestFactory<Test> kTestFactory{kSuite};     \
                                                               \
  void TestRoutine()

#define FAULT_TEST(name)                                         \
  FAULT_TEST_IMPL(CONCAT(TestRoutine, name), CONCAT(Test, name), \
                  TO_STRING(name), CONCAT(kTestFactory, name))

#else

#define FAULT_TEST_IMPL(TestRoutine, Test, name, kTestFactory) \
  void TestRoutine();                                          \
                                                               \
  class Test : public ::crutch::ITest {                        \
   public:                                                     \
    ::crutch::StringView Name() const noexcept override {      \
      return ::crutch::StringView{name};                       \
    }                                                          \
                                                               \
    ::crutch::StringView Suite() const noexcept override {     \
      return kSuite.Name();                                    \
    }                                                          \
                                                               \
    void Run() override {                                      \
      TestRoutine();                                           \
    }                                                          \
  };                                                           \
                                                               \
  static ::crutch::TestFactory<Test> kTestFactory{kSuite};     \
                                                               \
  void TestRoutine()

#define FAULT_TEST(name)                                         \
  FAULT_TEST_IMPL(CONCAT(TestRoutine, name), CONCAT(Test, name), \
                  TO_STRING(name), CONCAT(kTestFactory, name))

#endif