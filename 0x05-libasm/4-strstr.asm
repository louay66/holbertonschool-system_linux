BITS 64

global asm_strstr

section .text
   asm_strstr:
         push rbp
         mov rbp, rsp
         xor rax, rax
         xor rcx , rcx
         xor rbx , rbx
         xor r10 , r10
         xor r11, r11
         xor r9 , r9

   find_neddel:
         mov r9b , [rdi + rcx]
         mov r10b, [rsi + rbx]
         cmp r10b, 0
         je return_pointer
         inc rcx
         cmp r9b, r10b
         jne pass
         inc rbx
         jmp find_neddel

   research:
         mov r11 , rcx
         xor rbx, rbx
         jmp find_neddel
   pass:
      cmp r9b, 0
      je return
      jmp research
   return_pointer:
      mov rax , rdi
      add rax , r11
      jmp return
   return:
      mov rsp , rbp
      pop rbp
      ret
