/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:53 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:55 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Returns pointer to last occurrence of c in s (including \0).
char	*ft_strrchr(const char *s, int c)
{
	int		str_len;
	char	*ret_str;

	str_len = ft_strlen(s);
	ret_str = (char *)s;
	while (str_len >= 0)
	{
		if (ret_str[str_len] == (char) c)
			return (&ret_str[str_len]);
		str_len--;
	}
	return (0);
}
