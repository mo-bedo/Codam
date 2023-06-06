#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	return_line = create_return_line(buffer);
	buffer = create_next_buffer(buffer);
	return (return_line);
}

char	*create_next_buffer(char *buffer)
{
	char	*next_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_buffer = ft_calloc (ft_strlen(buffer) - i + 1);
	if (!next_buffer)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i])
		next_buffer[j++] = buffer[i++];
	free(buffer);
	return (next_buffer);
}

char	*create_return_line(char *buffer)
{
	char	*return_line;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	return_line = ft_calloc(i + 2);
	if (!return_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		return_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		return_line[i] = buffer[i];
	return (return_line);
}

char	*get_buffer(int fd, char *buffer)
{
	int		bytes_read;
	char	*read_buff;

	read_buff = malloc (BUFFER_SIZE + 1);
	if (!read_buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && new_line_check(buffer) == -1)
	{
		bytes_read = read(fd, read_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buff);
			return (NULL);
		}
		read_buff[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, read_buff);
	}
	free(read_buff);
	return (buffer);
}
