BITS 64

global asm_strpbrk

section .text
   asm_strpbrk:
         push rbp
         mov rbp, rsp
         xor rcx, rcx
         xor rax, rax
         xor rdx, rdx
   loop_in_dest:
      mov r10b , [rdi + rcx]
      cmp r10b, 0
      je return
      xor rdx, rdx
      jmp loop_in_source
   loop_in_source:
      mov r9b, [rsi + rdx]
      cmp r9b, 0
      je re_loop
      cmp r9b, r10b
      je get_match
      inc rdx
      jmp loop_in_source
   re_loop:
      inc rcx
      jmp loop_in_dest
   get_match:
	mov rax, rdi
	add rax, rcx
   jmp return
   return:
      mov rsp , rbp
      pop rbp
      ret