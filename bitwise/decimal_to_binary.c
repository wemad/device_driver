#include <stdio.h>
int main() {

	int num, i;
	scanf("%d", &num);
#if 0	
	for(i = 31; i >=0; i--) {
	     int bit = (num >> i) & 1;
	     printf("%d", bit);
	}
#endif
	for(i = 31; i >=0; i--) {
	     
	     printf("%s", num & (1 << i)? "1": "0");
	}	
}
