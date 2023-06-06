/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:28 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 16:24:09 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include "usleep.h"

static int	time_since_in_usec(const struct timeval since)
{
	struct timeval	current;
	int				time_diff;

	if (gettimeofday(&current, NULL) == -1)
	{
		printf("Gettimeofday error\n");
		return (-1);
	}
	time_diff = convert_to_us(current) - convert_to_us(since);
	return (time_diff);
}

int	ft_usleep(useconds_t sleep_time)
{
	struct timeval	start;
	int				time_diff;

	time_diff = 0;
	if (gettimeofday(&start, NULL) == -1)
	{
		printf("Gettimeofday error\n");
		return (0);
	}
	while (time_diff < (int) sleep_time)
	{
		usleep(250);
		time_diff = time_since_in_usec(start);
		if (time_diff == -1)
			return (0);
	}
	return (1);
}
