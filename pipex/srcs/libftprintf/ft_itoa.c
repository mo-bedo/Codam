/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:49:23 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:49:25 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	int_length(int n);

char	*ft_itoa(int n)
{
	int		int_len;
	char	*ret;
	long	n_long;

	int_len = int_length(n);
	n_long = n;
	ret = (char *) malloc(sizeof (char) * int_len + 1);
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	if (n_long < 0)
	{
		ret[0] = '-';
		n_long *= -1;
	}
	ret[int_len] = '\0';
	while (n_long > 0)
	{
		int_len--;
		ret[int_len] = n_long % 10 + 48;
		n_long /= 10;
	}
	return (ret);
}

static	int	int_length(int n)
{
	int		len;
	long	n_long;

	n_long = n;
	len = 0;
	if (n < 0)
	{
		len++;
		n_long *= -1;
	}
	if (n == 0)
		len++;
	while (n_long > 0)
	{
		n_long /= 10;
		len++;
	}
	return (len);
}
