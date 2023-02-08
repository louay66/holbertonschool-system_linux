BITS 64

global asm_strncasecmp

section .text
   asm_strncasecmp:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
         xor rax, rax
         xor r9, r9
         xor r11, r11

   loop_in_bytes_of_sour_and_dest:
         mov r9b, [rdi + rcx]
         mov r11b, [rsi + rcx]
         cmp r9b, 65
         jl recheck
         cmp r9b, 90
         jg recheck
         add r9b, 32
   recheck:
         cmp r11b, 65
         jl result
         cmp r11b, 90
         jg result
         add r11b, 32
   result:
         cmp rdx, 0
         je return
         mov eax, r9d
         sub eax, r11d
         cmp eax, 0
         jne return
         cmp r9b, 0
         je return
         dec rdx
         inc rcx
         jmp loop_in_bytes_of_sour_and_dest

   return:
         mov rsp , rbp
         pop rbp
         ret
