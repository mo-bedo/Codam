/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:51:11 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:51:13 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	int_length(int n);

int	ft_printitoa(int n)
{
	int		len_ret;
	char	*ret;
	long	n_long;

	len_ret = int_length(n);
	n_long = n;
	ret = (char *) ft_calloc(1, sizeof (char) * len_ret + 1);
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	if (n_long < 0)
	{
		ret[0] = '-';
		n_long *= -1;
	}
	while (n_long > 0)
	{
		len_ret--;
		ret[len_ret] = n_long % 10 + 48;
		n_long /= 10;
	}
	len_ret = write_str(ret);
	free(ret);
	return (len_ret);
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
