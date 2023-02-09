#ifndef THREAD_IMPL
#error Do not include this file directly
#endif

#ifdef FAULT_INJECTION

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