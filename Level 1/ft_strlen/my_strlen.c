int	my_strlen(char *str)
{
	char *end;

	end = str;
	while (end && *end)
		end++;
	return (end - str);
}
