/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:49:04 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:49:06 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	ret = malloc (size * count);
	if (!ret)
		return (0);
	ft_bzero(ret, size * count);
	return (ret);
}
