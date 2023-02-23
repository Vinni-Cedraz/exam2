char    *my_strcpy(char *s1, char *s2)
{
	char *dest;
	char *src;
	int i;

	if(!s1 || !s2)
		return "";
	dest = s1;
	src = s2;
	i = -1;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (dest);
}
