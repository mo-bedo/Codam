/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:49:59 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:01 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Writes len bytes of value c (in unsigned char) to b.
void	*ft_memset(void *b, int c, size_t len)
{
	while (len)
	{
		((unsigned char *)b)[len - 1] = (unsigned char) c;
		len--;
	}
	return (b);
}
