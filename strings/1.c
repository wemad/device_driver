#include <stdio.h>
#include <string.h> /* string function */

#define size 200

/*
 * my_strlen: calculate length of input string
 * @str: input string
 *
 * return: length of string
 */
long int my_strlen(char *str)
{
	long int count = 0;

	while (str[count])
		count++;

	return count;
}


int main()
{
	char str[size];
	printf("enter a string:");
#if 0
	scanf("%s", str); /* it will not read after the space */
	printf("out: %s\n", str);
	scanf("%[^\n]s", str); /* it will read from start to new line*/
	printf("out: %s\n", str);
#endif

	/*
	 * char * (char *dest, int n, FILE *Stream) another way to read string 
	 * read the character till 4 and append new line & null at last
	 */
	fgets(str, sizeof(str), stdin); 
	puts(str);
	printf("string length: %ld\n", strlen(str));
	printf("my_strlen: %ld\n", my_strlen(str));
}
