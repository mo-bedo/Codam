#include "libft.h"

static	int	search_str_set(char const s1, char const *set);
static	int	search_str_start(char const *s1, char const *set);
static	int	search_str_end(char const *s1, char const *set, int s1_len);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;
	size_t	k;

	if (!s1)
		return (0);
	start = search_str_start(s1, set);
	end = 0;
	if (!(start == ft_strlen(s1)))
		end = search_str_end(s1, set, ft_strlen(s1));
	if ((end + start + 1) < ft_strlen(s1))
		ret = (char *) ft_calloc(ft_strlen(s1) - end - start + 1, 1);
	else
		ret = (char *) ft_calloc(1, 1);
	if (!ret)
		return (0);
	k = 0;
	while ((ft_strlen(s1) - end - start) > 0)
	{
		ret[k] = s1[start];
		k++;
		start++;
	}
	return (ret);
}

static	int	search_str_end(char const *s1, char const *set, int s1_len)
{
	int	end;

	end = 0;
	while (s1[s1_len - 1 - end])
	{
		if (!search_str_set(s1[s1_len - 1 - end], set))
			break ;
		end++;
	}
	return (end);
}

static	int	search_str_set(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

static	int	search_str_start(char const *s1, char const *set)
{
	int	ret;

	ret = 0;
	while (s1[ret])
	{
		if (!search_str_set(s1[ret], set))
			break ;
		ret++;
	}
	return (ret);
}
