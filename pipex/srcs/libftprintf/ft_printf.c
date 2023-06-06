/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:03 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:05 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_char(char c);

int	ft_printf(const char *s, ...)
{
	va_list	arg_list;
	size_t	loop;
	size_t	ret;

	ret = 0;
	loop = 0;
	va_start(arg_list, s);
	while (s[loop])
	{
		if (s[loop] == '%' && (s[loop + 1] == 'd' || s[loop + 1] == 'i' \
			|| s[loop + 1] == 'c' || s[loop + 1] == 's' || s[loop + 1] == 'u' \
			|| s[loop + 1] == 'p' || s[loop + 1] == 'x' || s[loop + 1] == 'X' \
			|| s[loop + 1] == '%'))
		{
			ret += convert(arg_list, s[loop + 1]);
			loop += 2;
			continue ;
		}
		if (s[loop] == '%')
			loop++;
		ret += write(1, &s[loop], 1);
		loop++;
	}
	va_end(arg_list);
	return (ret);
}

int	convert(va_list arg_list, char s)
{
	int		ret;

	if (s == 'c')
		ret = write_char(va_arg(arg_list, int));
	if (s == 'd' || s == 'i')
		ret = ft_printitoa(va_arg(arg_list, int));
	if (s == 's')
		ret = write_str(va_arg(arg_list, char *));
	if (s == 'u')
		ret = ft_uitoa(va_arg(arg_list, unsigned int));
	if (s == 'p')
		ret = hexa_p((long long) va_arg(arg_list, void *));
	if (s == 'x')
		ret = hexa(va_arg(arg_list, unsigned int), 0);
	if (s == 'X')
		ret = hexa(va_arg(arg_list, unsigned int), 1);
	if (s == '%')
		return (write(1, "%", 1));
	return (ret);
}

int	write_str(char *str)
{
	int	ret;

	if (!str)
		ret = write(1, "(null)", 6);
	else
		ret = write(1, str, ft_strlen(str));
	return (ret);
}

static int	write_char(char c)
{
	return (write(1, &c, 1));
}
