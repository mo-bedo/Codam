/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:51:00 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:51:02 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Creates substring from s, starting at start and max len size (including \0)
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ret = (char *) ft_calloc(len + 1, 1);
	if (!ret)
		error_and_exit("malloc:");
	if (start > ft_strlen(s))
		return (ret);
	i = 0;
	while (len)
	{
		ret[i] = s[start];
		len--;
		i++;
		start++;
	}
	return (ret);
}
