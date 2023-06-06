//	Returns pointer to first occurrence of c (in char) in s (including \0).
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (c == '\0' && *s == '\0')
		return ((char *) s);
	return (0);
}
