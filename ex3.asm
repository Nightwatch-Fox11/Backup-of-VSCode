DSEG    SEGMENT
PROMPT1  DB  "INPUT HEXADECIMAL(4DIGITS):$"
HEXBUF  DB  5,0,5  DUP(0)
DISP    DB  0AH,ODH
BCDBUF  DB  6  DUP(0),'$'
DATA    ENDS
STACK1  SEGMENT  PARA  STACK
        DW 20H DUP(0)
STACK1  ENDS
COSEG   SEGMENT
        ASSUME CS:COSEG,DS:DATA,SS:STACK1
HEXBCD: MOV AX,DATA
        MOV DS, AX      
;输入1 、4 位十六进制数
        LEA DX,PROMPT   ;显示提示信息
        MOV AH,09H
        INT 21H
        LEA DX,HEXBUF   ;输入数据
        MOV AH,OAH
        INT 21H 
;ASCII 码转换为16位二进制数并存入BX中
        LEA SI,HEXBUF+2     ;取十六进制数ASCII 码首址
        MOV BX,0            ;暂存二进制数的寄存器清零
        MOV CH,HEXBUF+1     ;取输入数据个数
HEX1:   MOV AL,[SI]         ;取一个十六进制数字符
        CMP AL,'9'
        JBE NUMB            ;小于等于'9'是数字符
        SUB AL,07H          ;是字母符
NUMB:   AND AL,OFH
        MOV CL,4
        SAL BX,CL
        OR BL,AL
        INC SI
        DEC CH
        JNE HEX1
;确定十进制数的符号
        MOV  BCDBUF,'+'
        TEST BX, 8000H
        JNS  PLUS       ;是正数
        MOV  BCDBUF,'-' ;是负数
        NEG BX          ;求补后变为原码
;将二进制数转换为非组合型BCD码，从二进制;数高位起，进行15次加和乘
PLUS:   MOV CH,OFH        ;"加乘"运算的次数
LOP0:   SHL BX,1          ;最高位二进制数送CF
        CALL ADDIT        ;先加1位二进制数
        CALL MULT1        ;再乘2
        DEC CH
        JNE LOPO
        SHL BX,1        ;加最低位二进制数
        CALL ADDIT
;把非组合型BCD码转换为ASCII码形式
        LEA DI,BCDBUF+1
        MOV CX,5
LOP1:   OR BYTE PTR [DI],30H
        INC DI
        LOOP LOP1
;显示结果
        LEA DX,DISP
        MOV AH,09H
        INT 21H
        MOV AH,4CH 程序结束
        INT 21H
;多字节BCD码加1位二进制数子程序
ADDIT   PROC
        LEA DI,BCDBUF+5 ;从低位开始
        MOV CL,5        ;取字节数
ADD1:   MOV AL, [DI]    ;取BCD码
        ADC AL,0        ;加二进制数位(CF)
        AAA             ;十进制数运算校正
        MOV [DI],AL     ;存BCD码
        DEC DI
        DEC CL
        JNE ADD1
        RET
ADDIT   ENDP
;多字节BCD码乘2子程序
MULTI   PROC
        LEA DI,BCDBUF+5 ;从低位开始
        MOV CL,5
        CLC
MUL1:   MOV AL,[DI]     ;取BCD码
        ADC AL,AL       ;乘2
        AAA             ;十进制数运算校正
        MOV [DI],AL     ;存BCD码
        DEC DI
        DEC CL
        JNE MUL1
        RET
MULTI   ENDP
COSEG   ENDS
        END HEXBCD
