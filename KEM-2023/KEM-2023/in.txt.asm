.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib libucrt.lib
includelib ..\Debug\Library.lib
EXTRN comp: PROC
EXTRN concat: PROC
EXTRN copy: PROC
EXTRN len: PROC
EXTRN ConsNum: PROC
EXTRN ConsStr: PROC
EXTRN ConsBool: PROC
EXTRN consPause: proc
ExitProcess PROTO : DWORD

.STACK 4096
.CONST

	L1 dd 1
	L2 db "Hello" , 0
	L3 dd 15
	L4 dd 5
	L5 dd 50
	L6 dd 4
	L7 dd 16
	L8 db "string1" , 0
	L9 db "string2" , 0
	L10 dd 7
	L11 dd 83
	L12 dd 0

.DATA

	buffer BYTE 256 dup(0)
	sum_func DD 0
	t_Program DD 0
	e_Program DD 0
	g_Program DD 0
	x_Program DD 0
	str1_Program DD ?
	str2_Program DD ?
	str3_Program DD ?
	y_Program DD 0
	s_Program DD 0
	f_Program DD 0

.CODE

func PROC abc_func : DWORD 

push abc_func
push abc_func
call func
push EAX
pop EAX
pop EBX
add EAX, EBX
push EAX
pop sum_func

mov eax, sum_func
ret
func ENDP


Program PROC
START:

push L1
pop t_Program


mov EAX,t_Program
mov EBX, 1
sub EAX, EBX
je true1
jmp exit1

true1:
mov EAX, offset L2
push EAX
call ConsStr


exit1:
push L3
push L4
pop EAX
pop EBX
OR EAX, EBX
push EAX
pop e_Program

push L5
pop g_Program

push g_Program
call func
push EAX
push L6
pop EAX
pop EBX
add EAX, EBX
push EAX
push L3
push L7
pop EAX
pop EBX
AND EAX, EBX
push EAX
pop EBX
pop EAX
sub EAX, EBX
push EAX
pop x_Program

mov EAX, x_Program
push EAX
call ConsNum

push offset L8
pop str1_Program

push offset L9
pop str2_Program

push str1_Program
push str2_Program
push offset buffer
call concat
push EAX
pop str3_Program

mov EAX, str3_Program
push EAX
call ConsStr

push L1
pop y_Program


mov EAX,y_Program
mov EBX, 1
sub EAX, EBX
je true2
jmp exit2

true2:
push str1_Program
call len
push EAX
pop s_Program


mov EAX,s_Program
mov EBX, L10
sub EAX, EBX
je true3
jmp exit3

true3:
mov EAX, s_Program
push EAX
call ConsNum


exit3:
mov EAX, str2_Program
push EAX
call ConsStr


exit2:
push L11
pop f_Program

mov EAX, f_Program
push EAX
call ConsNum

mov eax, L12
push 0
call consPause
call ExitProcess
Program ENDP
end Program