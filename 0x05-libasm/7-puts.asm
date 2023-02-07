BITS 64
global asm_puts
extern asm_strlen
section .text
   asm_puts:
         push rbp
         mov rbp, rsp
         push rdi
         call asm_strlen
         pop rdi

         mov rdx, rax
         mov rax , 1
         mov rsi, rdi
         mov rdi , 1
         syscall

         mov rsp , rbp
         pop rbp
         ret
