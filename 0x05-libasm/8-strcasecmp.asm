BITS 64

global asm_strcasecmp

section .text
   asm_strcasecmp:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
         xor rax, rax
         xor rdx, rdx
         xor r11, r11

   loop_in_bytes_of_sour_and_dest:
         mov dl, [rdi + rcx]
         mov r11b, [rsi + rcx]
         cmp dl, 0
         je NULL_bytes
         cmp r11b, 0
         je NULL_bytes
         cmp dl, 65
         jl recheck
         cmp dl, 90
         jg recheck
         add dl, 32
   recheck:
         cmp r11b, 65
         jl result
         cmp r11b, 90
         jg result
         add r11b, 32
   result:
         mov eax, edx
         sub eax, r11d
         cmp eax, 0
         jne return
         cmp dl, 0
         je return
         inc rcx
         jmp loop_in_bytes_of_sour_and_dest
   NULL_bytes:
         mov eax, edx
         sub eax, r11d
         jmp return

   return:
         mov rsp , rbp
         pop rbp
         ret
