#pragma once

struct StackState {
  void* rsp;
};

extern "C" void SetupStackState(StackState* state,
                                void (*trampoline)(void*, void*, void*, void*, void*, void*, void*),
                                void* landing_pad) noexcept;

extern "C" void SwitchStackState(StackState* current, StackState* state) noexcept;