/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:48:53 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:48:57 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	ret;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	minus = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		minus = str[i];
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret *= 10;
		ret += (str[i] - 48);
		i++;
	}
	if (minus == 45)
		return (-(ret));
	return (ret);
}
