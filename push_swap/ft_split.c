#include "push_swap.h"

static int		ft_str_count(char const *s, char c);
static char		*ft_write_str(char const *s, char c);
static size_t	ft_strlen(char *str);
static size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);

char	**ft_split(char const *s, char c)
{
	char	**ret_arr;
	size_t	str_amount;
	size_t	i;

	if (!s | !s[0])
		error_check(NULL, NULL);
	str_amount = ft_str_count(s, c);
	ret_arr = (char **) malloc((sizeof (char *) * (str_amount + 2)));
	if (!ret_arr)
		error_check(NULL, NULL);
	ret_arr[str_amount + 1] = 0;
	i = 1;
	while (i <= str_amount)
	{
		while (*s == c)
			s++;
		ret_arr[i] = ft_write_str(s, c);
		if (!ret_arr[i])
			free_strings(ret_arr, 1);
		s += ft_strlen(ret_arr[i]);
		i++;
	}
	return (ret_arr);
}

static char	*ft_write_str(char const *s, char c)
{
	size_t	i;
	char	*ret_s;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	ret_s = (char *) malloc(sizeof (char) * i + 1);
	if (!ret_s)
		return (NULL);
	ft_strlcpy(ret_s, s, i + 1);
	return (ret_s);
}

static int	ft_str_count(char const *s, char c)
{
	size_t	str_num;
	size_t	j;

	str_num = 0;
	j = 0;
	while (s[j])
	{
		if (((s[j + 1] == c) || (s[j + 1] == '\0')) && (s[j] != c))
			str_num++;
		j++;
	}
	return (str_num);
}

static size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

////	Copies dstsize -1 from src to dst. \0 the result.
static size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen((char *) src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while ((i < (dstsize - 1)) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
