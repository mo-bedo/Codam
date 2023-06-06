/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:22 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:22 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "time_utils.h"
#include <stdio.h>

void	print_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%i %i has taken a fork\n", \
		(int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
		printf("%i %i is eating\n", \
		(int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);

		printf("%i %i is sleeping\n", \
		(int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);

		printf("%i %i is thinking\n", \
		(int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	pthread_mutex_unlock(&philo->data->print);
}

void	print_has_died(t_philo *philo)
{
	printf("%i %i died\n", \
	(int) time_since_in_ms(philo->data->simulation_t0), philo->number);
}
