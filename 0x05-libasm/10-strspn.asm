BITS 64

global asm_strspn

section .text
   asm_strspn:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
         xor rax, rax
         xor rdx, rdx
   loop_in_dest:
      mov r10b , [rdi + rax]
      cmp r10b, 0
      je return
      xor rcx, rcx
      jmp loop_in_source
   loop_in_source:
      mov r9b, [rsi + rcx]
      cmp r9b, 0
      je return
      cmp r9b, r10b
      je re_loop
      inc rcx
      jmp loop_in_source
   re_loop:
      inc rax
      jmp loop_in_dest
   return:
      mov rsp , rbp
      pop rbp
      ret