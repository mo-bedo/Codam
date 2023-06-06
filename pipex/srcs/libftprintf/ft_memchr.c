/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:49:49 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:49:51 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Locates first occurrence of (unsigned char) c in s.
//	Returns pointer to the located byte.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		d;
	const unsigned char	*str;

	str = (unsigned char *) s;
	d = c;
	i = 0;
	while (i < n)
	{
		if (*str == d)
			return ((void *)str);
		str++;
		i++;
	}
	return (0);
}
