BITS 64
global asm_strlen
section .text
asm_strlen:
   push rbp; puch base pointer to the end of the section after return value of procedure(function)
   mov rbp, rsp ; put the value of stack pointer in RBP
   xor rcx, rcx  ; xor tow value equal 0
loop_strlen:
   cmp byte [rdi + rcx], 0 ; rdi is dest value and rcx is counter equal 0 so  [rdi + rcx] is the pointer to string
   je return   ; if [rdi + rcx] is 0 go to return section
   inc rcx ; incrment counter
   jmp loop_strlen ; if rcx is not equal 0 loop again

return:
   mov rax, rcx ; mov len of string to rax
   mov rsp , rbp ; return the stack pointer value as it is was
   pop rbp ; pop rbp
   ret ; return
