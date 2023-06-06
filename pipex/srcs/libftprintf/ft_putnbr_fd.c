/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:17 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:19 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		out;
	long	numb;

	numb = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		numb *= -1;
	}
	out = numb % 10 + 48;
	numb /= 10;
	if (numb > 0)
		ft_putnbr_fd(numb, fd);
	write(fd, &out, 1);
}
