; the length of the string is stored in rax.
; Dec rax by one to get rid of the \0.
; mov 16 in our counter as there are 16 bytes.
; set pointer to the variable where we want to  store the length;
; rotate rax by 4 bits. The mp stores from right to left we read from left to right.
; move the the 8 bits to bl register.
; and with 0fh to to get the required number.
; compare with 09H. If greater then add 07H
; else add 30H
; mov the value to [rsi]
; inc rsi
; dec counter
; repeat if the counter is not 0.
; print value at length.

section .data
str1: db "Enter number",0xA
len1: equ $-str1

cnt : db 0

section .bss
input:resb 20
length : resb 20

%macro wr 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
%endmacro

section .text
global _start
_start:
wr 1,1,str1,len1      
syscall
wr 0,0,input,200      
syscall

DEC rax
mov byte[cnt],16
mov rsi,length
up:
rol rax,4
mov bl,al
AND bl,0FH
CMP bl,09H
   JBE l
   ADD bl,07H
   l:
   ADD bl,30H
   mov byte[rsi],bl
   inc rsi
   dec byte[cnt]
   jnz up
  
wr 1,1,length,16
syscall

mov rax,60
mov rdi,00
syscall