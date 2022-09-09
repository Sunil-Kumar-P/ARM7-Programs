#include<lpc214x.h>
void uart_init(void); 
unsigned int delay; 
unsigned char *ptr; 
unsigned char arr[]="HELLO WORLD\r"; 
int main() 
{ 
	while(1) 
	{ 
		uart_init(); 
		ptr = arr; 
		while(*ptr!='\0') 
		{ 
			U0THR=*ptr++; 
			while(!(U0LSR & 0x20)== 0x20); 
			for(delay=0;delay<=600;delay++); 
		} 
		for(delay=0;delay<=60000;delay++); 
	} 
} 
void uart_init(void) 
{ 
	PINSEL0=0X0000005; 
	U0LCR = 0X00000083; 
	U0DLM = 0X00;
	U0DLL = 0x13;
	U0LCR = 0X00000003; 
}
