data segment;定义一个名为data的数据段
	a db 5;定义了一个常量，并分配一个字节空间存储这个常量5
	b db 6;同上
data ends;定义的数据段结束

code segment;定义一个名为code的代码段
	assume cs:code,ds:data;伪指令assume不分配内存，只是指定了存放各个段段基址的段寄存器
start:
	mov ax,data;DS重定位
	mov ds,ax
	mov al,a;取第一个操作数
	mov bl,b;取第二个操作数
	add al,bl;俩操作数相加，结果存放在al寄存器
	mov ah,4ch;返回DOS
	int 21h
code ends;定义的代码段结束
end start;END表示程序结束