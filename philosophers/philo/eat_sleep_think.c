/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:28 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 16:24:09 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "utils.h"
#include "usleep.h"
#include "start_simulation.h"
#include "philo.h"
#include <stdio.h>

void	start_sleeping(t_philo *philo)
{
	print_is_sleeping(philo);
	ft_usleep(philo->data->sleep_time * 1000);
//	if (!ft_usleep(convert_to_us(philo->data->sleep_time)))
//		printf("Usleep error\n");
}

void	start_eating_last_philo(t_philo *philo)
{
	mutex_lock_wrap(&philo->data->stop_simulation);
	if (philo->data->stop)
	{
		mutex_unlock_wrap(&philo->data->stop_simulation);
		return ;
	}
	mutex_unlock_wrap(&philo->data->stop_simulation);
	mutex_lock_wrap(&philo->data->forks[0]);
	print_taken_fork(philo);
	mutex_lock_wrap(&philo->data->forks[philo->number - 1]);
	print_taken_fork(philo);
	print_is_eating(philo);
	gettimeofday(&philo->started_eating, NULL);

	ft_usleep(philo->data->eat_time * 1000);

	mutex_unlock_wrap(&philo->data->forks[0]);
	mutex_unlock_wrap(&philo->data->forks[philo->number - 1]);
}

void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_simulation);
//	mutex_lock_wrap(&philo->data->stop_simulation);
	if (philo->data->stop)
	{
//		mutex_unlock_wrap(&philo->data->stop_simulation);
		pthread_mutex_lock(&philo->data->stop_simulation);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_simulation);
	pthread_mutex_lock(&philo->data->forks[philo->number - 1]);
	print_taken_fork(philo);
	pthread_mutex_lock(&philo->data->forks[philo->number]);
	print_taken_fork(philo);
	print_is_eating(philo);
	gettimeofday(&philo->started_eating, NULL);
	ft_usleep(philo->data->eat_time * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->number - 1]);
	pthread_mutex_unlock(&philo->data->forks[philo->number]);
}

void	start_thinking(t_philo *philo)
{
	print_is_thinking(philo);
	routine((void *) philo);
}
