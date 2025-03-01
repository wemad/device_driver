#include <stdio.h>

int my_strlen(char *str){
	int count = 0;
	while(*str)
		count++, str++;
	return count;
}

int main() {
	char str[10];
	fgets(str, sizeof(str) , stdin);
	printf("strlen = %d", my_strlen(str));
	return 0;

}
