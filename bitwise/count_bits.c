#include <stdio.h>

void count_bits(int n){
	int count = 0;
	while(n) {
		n = n & n - 1;
		count++;
	}
	printf("count = %d", count);
}

int main() {

	int num, i;
	int count = 0;
	scanf("%d", &num);
	for(i = 0; i<=31; i++) {
	     if(num & (1 << i))
		     count++;
	}	
	printf("%d\n", count);
	count_bits(num);
}
