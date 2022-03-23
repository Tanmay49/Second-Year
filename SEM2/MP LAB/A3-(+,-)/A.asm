section .data
array : dq 0x0000123412341234,0x11111111ffffffff,0x12111111ffffffff,0xff111111ffffffff,0xff111111ffffffff
str1: db "positive",0xA
len1: equ $-str1
str2: db "negative",0xA
len2: equ $-str2
section .bss

cnt : resb 10
cntp : resb 10
cntn : resb 10

section .text

global _start

_start:

mov rsi,array
mov byte[cnt],5
mov byte[cntn],0
mov byte[cntp],0

upi:
	mov rax,qword[rsi]
	;mov rsi, array
	BT rax,63

	jc x
	inc byte[cntp]
	jmp l
	x:
	inc byte[cntn]
l:
	add rsi,8
	dec byte[cnt]
	jnz upi



mov al,byte[cntp]
add al,30H
mov byte[cntp],al
mov al,byte[cntn]
add al,30H
mov byte[cntn],al

mov rax,1
mov rdi,1
mov rsi,str1
mov rdx,len1
syscall

mov rax,1
mov rdi,1
mov rsi,cntp
mov rdx,4
syscall

mov rax,1
mov rdi,1
mov rsi,str2
mov rdx,len2
syscall

mov rax,1
mov rdi,1
mov rsi,cntn
mov rdx,4
syscall

mov rax,60
mov rdi,00
syscall