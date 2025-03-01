#include <stdio.h>
void binary(int num) {
	int i;
	for(i = 31; i >=0; i--)
	    printf("%s", num & (1 << i)? "1": "0");
	
	    printf("\n");
}

int reverse(int num) {

	int i, rev_num = 0;
	 for (i = 0; i <= 31; i++) {
	 	if(num & (1 << i))
			rev_num |= 1 << (31 - i);
	 }
	 return rev_num;
}

int main() {

	int num, rev;
	scanf("%d", &num);
#if 0	
	for(i = 31; i >=0; i--) {
	     int bit = (num >> i) & 1;
	     printf("%d", bit);
	}
#endif
	binary(num);
	rev = reverse(num);
	binary(rev);
	return 0;
}
