DSEG    SEGMENT
        VARX    DB 20H
        VARY    DB 46H
        VARZ    DW ?
        VAROPR  DB 0    ;标志变量,0表示无符号数,1表示有符号数
DSEG    ENDS
STACK1  SEGMENT PARA STACK
        DW 20H DUP(0)
STACK1  ENDS
CSEG    SEGMENT
        ASSUME CS:CSEG,DS:DSEG,SS:STACK1
START:
        MOV AX, DSEG
        MOV DS, AX

        XOR AH, AH  ;取X值
        MOV AL, VARX

        ;(5X+2Y-7)/2
        MOV CL, VAROPR
        CMP CL, 0       
        JZ UNSIG    ;无符号数计算则跳转

        MOV CL, 5   ;符号数计算5X
        IMUL CL
        MOV BX, AX

        XOR AH, AH  ;取Y值
        MOV AL, VARY

        MOV CL, 2   ;符号数计算2Y
        IMUL CL
        ADD BX, AX  ;BX中存5X+2Y

        SUB BX, 7   ;BX中存5X+2Y-7

        MOV AX, BX
        MOV CL, 2
        IDIV CL     ;AX中存(5X+2Y-7)/2
        JMP RESULT
UNSIG:
        MOV CL, 5   ;无符号数计算5X
        MUL CL
        MOV BX, AX

        XOR AH, AH
        MOV AL, VARY

        MOV CL, 2   ;无符号数计算2Y
        MUL CL
        ADD BX, AX  ;BX中存5X+2Y
        SUB BX, 7   ;BX中存5X+2Y-7
        MOV AX, BX
        MOV CL, 2
        DIV CL      ;AX中存(5X+2Y-7)/2
RESULT:
        MOV VARZ, AX

        MOV AH, 4CH
        INT 21H
CSEG    ENDS
        END START


