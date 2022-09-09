// Display the Hex digits 0 to F on a 7-segment LED interface, with an appropriate delay in between.
/*\\\\\\\\\\\\\\\DISPLAY ARE CONNECTED IN COMMON CATHODE MODE\\\\\\\\\\\\\\\\\\\\\
Port0 Connected to data lines of all 7 segement displays
a = P0.16 
b = P0.17 
c = P0.18 
d = P0.19 
e = P0.20 
f = P0.21 
g = P0.22 
dot = P0.23 
Select lines for four 7 Segments 
DIS1 P0.28 
DIS2 P0.29 
DIS3 P0.30 
DIS4 P0.31 
*/
#include<lpc214x.h>
unsigned int delay, count=0, Switchcount=0; 
unsigned int Disp[16]={0x003F0000, 0x00060000, 0x005B0000, 0x004F0000, 0x00660000,0x006D0000, 0x007D0000, 0x00070000, 0x007F0000, 0x006F0000, 0x00770000,0x007C0000,0x00390000, 0x005E0000, 0x00790000, 0x00710000 }; 
int main (void) 
{ 
	PINSEL1 = 0x00000000; 
	IO0DIR = 0xF0FF0000; 
	while(1) 
	{ //Display values on Seven Segment 
		IO0SET = 0x10000000; 
		IO0CLR = 0x00FF0000; 
		for(delay=0;delay<100;delay++) 
		IO0SET = Disp[Switchcount]; // display the values 0 to F one after the other 
		for(delay=0;delay<1000000;delay++) 
		{} 
		Switchcount++; 
		if(Switchcount == 16) // after F go back to 0 
		{ 
			Switchcount = 0;
		} 
	} 
}
