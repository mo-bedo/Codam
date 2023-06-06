/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:47 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:49 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//  Compares s1 and s2 up to n chars and in unsigned chars.
//  Returns the difference
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;
	int				i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && n)
	{
		str1 = s1[i];
		str2 = s2[i];
		if (str1 != str2)
			return (str1 - str2);
		i++;
		n--;
	}
	return (str1 - str2);
}
