#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_buffer(int fd, char *next_buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(int count);
int		ft_strlen(char *str);
int		new_line_check(char *bufffer);
char	*create_return_line(char *buffer);
char	*create_next_buffer(char *buffer);

#endif
