#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int	ft_uitoa(unsigned int n);
int	ft_itoa(int n);
int	ft_printf(const char *s, ...);
int	write_str(char *s);
int	ft_strlen(char *s);
int	hexa(long long nb, int up);
int	convert(va_list arg_list, char s);
int	hexa_p(unsigned long long nb);

#endif
