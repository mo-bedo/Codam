#include "get_next_line.h"

char	*ft_strjoin(char *buffer, char *add_to_buff)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!buffer)
		buffer = ft_calloc(1);
	if (!buffer || !add_to_buff)
		return (NULL);
	ret = ft_calloc(ft_strlen(buffer) + ft_strlen(add_to_buff) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	if (buffer)
		while (buffer[++i])
			ret[i] = buffer[i];
	j = 0;
	while (add_to_buff[j])
		ret[i++] = add_to_buff[j++];
	free(buffer);
	return (ret);
}

char	*ft_calloc(int count)
{
	char	*ret;

	ret = malloc (sizeof(char) * count);
	if (!ret)
		return (0);
	while (count)
	{
		count--;
		ret[count] = '\0';
	}
	return (ret);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

//	Returns position of newline character. -1 if no new line is present
int	new_line_check(char *buffer)
{
	int	i;

	if (!buffer)
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
