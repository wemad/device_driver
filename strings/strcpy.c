#include <stdio.h>
#include <string.h> /* string function */

#define size 200

/*
 * my_strlen: calculate length of input string
 * @str: input string
 *
 * return: length of string
 */
char *my_strcpy(char *str, char *destn)
{
	while(*str) {
		*destn++ = *str++;
	}
	*destn = *str;
	return destn;
}

char *my_strcat(char *str, char *destn){

	while(*destn) {
		destn++;
	}

	while(*str)
		*destn++ = *str++;

	*destn = '\0';

}

int my_strcmp(char *str, char search){

	while(*str) {
		if (*str != *search)
			return 0;
		str++;
		*search++
	}
	if(!*serach)
		return 1;
}
char *my_strstr(char *str, char *serach){

	while(*str) {
		if(*str == *search && my_strcmp(str, search))
			return str;
		str++;
	}
	return NULL;
}

int main()
{
	char str[size];
	char dest[size] = {"hello "};
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
	my_strcpy(dest, str);
	puts(str);
}
