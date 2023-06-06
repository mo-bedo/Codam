#include "libft.h"

//	Returns pointer to last occurrence of c in s (including \0).
char	*ft_strrchr(const char *s, int c)
{
	int		str_len;
	char	*ret_str;

	str_len = ft_strlen(s);
	ret_str = (char *)s;
	while (str_len >= 0)
	{
		if (ret_str[str_len] == (char) c)
			return (&ret_str[str_len]);
		str_len--;
	}
	return (0);
}
