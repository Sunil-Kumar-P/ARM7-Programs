	AREA ASCEND, CODE, READONLY
	ENTRY
	MOV R8,#4
	LDR R2, =SVALUE
	LDR R3,=DVALUE
LOOP LDR R1,[R2],#4
	STR R1,[R3],#4
	SUBS R8,R8,#1
	CMP R8,#0
	BNE LOOP
	MOV R7,#3
NXTPAS MOV R5,R7
	LDR R1,=DVALUE
NXTCMP LDR R2, [R1],#4
	LDR R3,[R1]
	CMP R2,R3
	BLT NOSWP
	STR R2,[R1],#-4
	STR R3,[R1]
	ADD R1,R1,#4
NOSWP SUBS R5,R5,#1
	BNE NXTCMP
	SUBS R7,R7,#1
	BNE NXTPAS
STOP B STOP
SVALUE DCD 0X44,0X11,0X33,0X22
	AREA DATA1,DATA,READWRITE
DVALUE DCD 0X00
	END