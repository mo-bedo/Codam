#include "libft.h"

//	Copies s1 in an allocated string and returns the new string.
char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	i;

	ret = (char *) malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
