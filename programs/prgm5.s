	AREA SQUARE,CODE,READONLY
	ENTRY
	MOV R1,#0X3
	LDR R0,=LUT
	MOV R1,R1,LSL#0X2
	ADD R0,R0,R1
	LDR R3,[R0]
STOP B STOP
LUT DCD 0X0,0X1,0X4,0X9,0X16,0X25,0X36,0X49,0X64,0X81,0X100
	END