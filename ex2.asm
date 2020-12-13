DSEG    SEGMENT
        BUF     DB -1, 20, 3, 30, -5, 15, 100, -54, 0, 4, 78, 99, -12, 32, 3, 23, -7, 24, 60,-51
DSEG  ENDS
ESEG     SEGMENT
        RES1  DB  0
        RES2  DB  0
        RES3  DB  0
ESEG     ENDS
STACK1  SEGMENT PARA STACK
        DW 20H DUP(0)
STACK1  ENDS
CODE    SEGMENT
ASSUME  CS:CODE,DS:DSEG,ES:ESEG,SS:STACK1
START:
        MOV    AX,  DSEG        ;开始初始化
        MOV    DS,  AX
        MOV    AX,  ESEG
        MOV    ES,  AX
        LEA    SI,  BUF         ;将BUF数组首地址存入SI

        MOV    RES1, 0      ;再次确保存储单元为零
        MOV    RES2, 0
        MOV    RES3, 0

        MOV    CX,20       ;根据数据个数定义循环次数
LOP:
        MOV     AL, [SI]         ;取操作数置入AL
        CMP     AL,0            ;将操作数与0比较
        JL      BELOW0          ;若小于0则跳转BELOW0
        CMP     AL,5            ;不小于0情况下与5比较
        JLE     BELOW5          ;若小于等于5则跳转BELOW5
        INC     RES1            ;操作数大于5,RES1加一
        JMP     NEXT            ;跳转至下一操作数
BELOW0:
        INC     RES2            ;操作数小于0,RES2加一
        JMP     NEXT            ;跳转至下一操作数
BELOW5:
        INC     RES3            ;操作数大于0小于等于5,RES3加一
        JMP     NEXT            ;跳转至下一操作数
NEXT:
        INC     SI
        LOOP    LOP
        MOV     AH,4CH
        INT     21H
CODE    ENDS
        END     START
