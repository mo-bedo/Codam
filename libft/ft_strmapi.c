#include "libft.h"

//	Applies f to s. Creates new string from results and returns it.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	if (!s || !f)
		return (0);
	ret = (char *) malloc(sizeof (char) * (ft_strlen(s)) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
