/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:32 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 13:24:57 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdbool.h>

unsigned long	convert_to_us(const struct timeval time)
{
	unsigned long	time_in_us;

	time_in_us = time.tv_sec * 1000000;
	time_in_us += time.tv_usec;
	return (time_in_us);
}

unsigned long	convert_to_ms(const struct timeval time)
{
	unsigned long	time_in_ms;

	time_in_ms = (unsigned long) time.tv_sec * 1000;
	time_in_ms += (unsigned long) time.tv_usec / 1000;
	return (time_in_ms);
}

unsigned long	time_since_in_ms(const struct timeval since)
{
	struct timeval	current;
	unsigned long			time_dif;

	if (gettimeofday(&current, NULL) == -1)
		printf("Gettimeofday error\n");
	time_dif = convert_to_ms(current) - convert_to_ms(since);
	return (time_dif);
}

struct timeval	get_time_to(char *time_to)
{
	struct timeval	time;
	int				temp;
	int				seconds;

	seconds = 0;
	temp = convert_string_to_int(time_to);
	if (temp / 1000)
	{
		seconds = temp / 1000;
		temp -= seconds * 1000;
	}
	time.tv_sec = seconds;
	time.tv_usec = temp * 1000;
	return (time);
}

bool	has_time_to_die_expired(t_philo *philo)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		printf("Gettimeofday error\n");
	if (philo->started_eating.tv_usec)
	{
		if (convert_to_ms(current) - convert_to_ms(philo->started_eating) > philo->data->die_time)
			return (true);
	}
	else if (convert_to_ms(current) - convert_to_ms (philo->data->simulation_t0) > (philo->data->die_time))
	{
		return (true);
	}
	return (false);
}
