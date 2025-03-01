#include <stdio.h>

void binary(int num) {
	int i;
	for (i = 31; i >=0; i--)
	{
		printf("%d", (num >> i) & 1);
		if ((i % 4) == 0)
		printf(" ");	
	}
	printf("\n");
}

void reversebits(int n)
{
	int i;
	int r  = 0;
	for(i = 1; i <= 32; i++) {
		//r = r << 1 | n & 1; combine logic
		printf("%d", n & 1);
		n = n >> 1;
		if ((i % 4) == 0)
			printf(" ");

	}
}

void swap_odd_even(int number) {
	int even_mask = (number & 0xAAAAAAAA) >> 1;
	int odd_mask  = (number & 0x55555555) << 1;
	int shifted_number = even_mask | odd_mask;
	printf("swapped number=%d", shifted_number);
}

int clear_range_of_bits(int n, int start, int end) {
	
	int mask = ~(((1 << (end - start + 1)) - 1) << start);
	printf("after clearing:%d\n", n & mask);
	return n & mask;
}

int count_set_bits(int n) {
	int count = 0;
	while(n) {
		n = n & n - 1;
		count++;
	}
	return count;
}

char convert_lowerto_upper_and_vice_verse(char a) {
	return a ^ 0x20;
}

void main() {

	int number = 0x12345678;
	scanf("%d", &number);
	binary(number);
	number = clear_range_of_bits(number, 2, 3);
	
	binary(number);

	char c  = convert_lowerto_upper_and_vice_verse('A');
	printf("big case:A ---> %c\n", c);
	number = count_set_bits(number);
	printf("set bits: %d", number);

}
