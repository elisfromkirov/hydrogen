  .text

  .globl _SetupStackState
_SetupStackState:
  # rsp stores address of thread stack
  # rdi stores address of stack state structure
  # rsi stores address of trampoline function
  # rdx stores address of landing pad

  # load stack pointer from stack state structore

  movq (%rdi), %rcx

  # now rcx stores address of stack

  # exchange stack pointers

  xchgq %rcx, %rsp

  # now rsp stores address of stack
  # now rcx stores address of thread stack

  # setup stack

  pushq %rdx
  pushq $0
  pushq %rsi
  pushq $0
  pushq $0
  pushq $0
  pushq $0
  pushq $0
  pushq $0

  # now stack is
  # +56(%rsp)    landing pad address
  # +48(%rsp)    trampoline return address
  # +40(%rsp)    trampoline address
  # +32(%rsp)    0
  # +32(%rsp)    0
  # +24(%rsp)    0
  # +16(%rsp)    0
  #  +8(%rsp)    0
  #     %rsp     0

  # exchange stack pointers

  xchgq %rcx, %rsp

  # now rsp stores address of thread stack
  # now rcx stores address of stack

  # save stack pointer to stack state structore

  movq %rcx, (%rdi)

  # now stack state structure contains address of stack top

  # return

  retq

  .globl _SwitchStackState
_SwitchStackState:
  # rdi stores address of current stack state structure
  # rsi stores address of target stack state strucutre

  # store callee saved registers

  pushq %rbx
  pushq %rbp
  pushq %r12
  pushq %r13
  pushq %r14
  pushq %r15

  # store rsp to current stack state structure

  movq %rsp, (%rdi)

  # load rsp from target stack state structure

  movq (%rsi), %rsp

  # load callee saved registers

  popq %r15
  popq %r14
  popq %r13
  popq %r12
  popq %rbp
  popq %rbx

  # return

  retq