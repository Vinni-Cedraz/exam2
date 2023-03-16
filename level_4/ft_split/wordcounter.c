#include <stdio.h>
#include <stdlib.h>
static int is_whitespace(char c){
  return(c == ' ' || c == '\t' || c == '\0');
}

int wordcounter(char *s)
{
	int inside_word = 0;
	int words = 0;
	while (*s)
	{
		if (is_whitespace(*s))
			inside_word = 0;
		else if (!inside_word){
			words++;
			inside_word = 1;
		}
		s++;
	}
	return (words);
}

int main()
{
	char *s;
	s = malloc(100);
	s = "	  	this   is a test I love avocados   	 ";
	printf("%d\n", wordcounter(s));
}
