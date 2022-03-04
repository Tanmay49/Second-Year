section .data
str1: db "You entered : " , 0xA
len1: equ $-str1
str3:db "Enter your name" ,0xA
len3:equ $-str3

cnt: db 0
section .bss
name : resb 20

section .text
global _start
_start:
   mov rax,1
   mov rdi,1
   mov rsi,str3
   mov rdx,len3
   syscall
   mov rbx,name
   mov byte[cnt],0x5

   read:
       mov rax,0
       mov rdi,0
       mov rsi,rbx
       mov rdx,17
       syscall
       add rbx,17
       dec byte[cnt]
       jnz read
   mov rbx,name
   mov byte[cnt],0x5
   
   mov rax,1
   mov rdi,1
   mov rsi,str1
   mov rdx,len1
   syscall

   print:
       mov rax,1
       mov rdi,1
       mov rsi,rbx
       mov rdx,17
       syscall
       add rbx,17
       dec byte[cnt]
       jnz print
   
   syscall
   
   mov rax,60
   mov rdi,00
   syscall
