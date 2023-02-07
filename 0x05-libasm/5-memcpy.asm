BITS 64

global asm_memcpy

section .text
   asm_memcpy:
         push rbp
         mov rbp, rsp
   loop_in_memory:
      cmp rdx, 0
      je return
      mov bl ,[rsi]
      mov [rdi], bl
      inc rdi
      inc rsi
      dec rdx
      jmp loop_in_memory
   return:
      mov rsp , rbp
      pop rbp
      ret
