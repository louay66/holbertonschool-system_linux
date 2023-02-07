BITS 64

global asm_strcasecmp

section .text
   asm_strcasecmp:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
         xor rax, rax
         xor rdx, rdx
         xor rbx, rbx

   loop_in_bytes_of_sour_and_dest:
            mov dl, [rdi + rcx]
            mov bl, [rsi + rcx]
            mov r8b, [rdi]
            mov r9b, [rsi]
            cmp r8b, 0
            je result_zero
            cmp r9b, 0
            je result_zero
            cmp dl, 65
            jl recheck
            cmp dl, 90
            jg recheck
            add dl , 32
   recheck:
            cmp bl, 65
            jl result
            cmp bl, 90
            jg result
            add bl, 32
   result:
      mov eax, edx
      sub eax, ebx
      cmp eax, 0
      jne return
      cmp edx, 0
      je return
      inc rcx
      jmp loop_in_bytes_of_sour_and_dest
   result_zero:
      mov eax, edx
      sub eax, ebx
      jmp return

   return:
   mov rsp , rbp
   pop rbp
   ret
