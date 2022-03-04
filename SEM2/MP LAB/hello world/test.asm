section .data
str: db "Hello, world"

section .text
global _start
_start:
   mov rax,1
   mov rdi,1
   mov rsi,str
   mov rdx,16
   syscall
   mov rax,60
   mov rdi,00
   syscall