#include <stdio.h>
int main() {

	int num = 0x12345678;
	int first = (0xff000000 & num) >> 24;
	int secound = (0x000000ff & num) << 24;
        int third = (0x00ff0000 & num) >> 8;
	int fourth = (0x0000ff00 & num) << 8; 	
		
	printf("swapped number:%x\n", first | secound | third | fourth);
}
