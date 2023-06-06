/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:49:01 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:49:03 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Writes n zeroed bytes to string s
void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = s;
	while (n)
	{
		temp[n - 1] = '\0';
		n--;
	}
	return ;
}
