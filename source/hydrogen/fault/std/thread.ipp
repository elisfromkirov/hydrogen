#ifndef THREAD_IMPL
#error Do not include this file directly
#endif

#if defined(FAULT_STD)

#elif defined(FAULT_RUNTIME)

namespace hydrogen {

namespace fault {

template <typename Function>
thread::thread(Function&& function)
    : impl_{::crutch::MakeUniquePtr<Thread>(::std::forward<Function>(function))} {
}

}  // namespace fault

}  // namespace hydrogen

#else

#endif