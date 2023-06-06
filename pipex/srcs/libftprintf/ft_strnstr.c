/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:50 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:52 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	This function locates the first occurrence of 'needle' in 'haystack' (while
//  searching less bytes then len. If needle is empty, haystack is returned; if
//  needle occurs nowhere in haystack, NULL is returned; otherwise a pointer to
//  the first character of the first occurrence of needle is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	k;
	int	needle_len;

	if ((!(*needle)) || (haystack == needle))
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (len && haystack[i])
	{
		k = i;
		j = 0;
		while ((haystack[k] == needle[j]) && (haystack[k] != 0) && (len - j))
		{
			j++;
			k++;
		}
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (0);
}
