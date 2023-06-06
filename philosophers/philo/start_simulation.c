/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:27 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 16:22:58 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eat_sleep_think.h"
#include "utils.h"
#include "usleep.h"

void	*start_simulation_one(void *input)
{
	t_philo	*philo;

	philo = (t_philo *) input;
	while (1)
	{
		mutex_lock_wrap(&philo->data->stop_simulation);
		if (philo->data->stop)
		{
			mutex_unlock_wrap(&philo->data->stop_simulation);
			return (NULL);
		}
		mutex_unlock_wrap(&philo->data->stop_simulation);
		if (!ft_usleep(200))
			return (NULL);
	}
}

void	routine(void *input)
{
	t_philo	*philo;

	philo = (t_philo *) input;
	if (philo->number == philo->data->number_of_philosophers)
		start_eating_last_philo(philo);
	else
		start_eating(philo);
	pthread_mutex_unlock(&philo->data->eat_complete);
//	mutex_lock_wrap(&philo->data->eat_complete);
	philo->has_to_eat--;
	pthread_mutex_unlock(&philo->data->eat_complete);
//	mutex_unlock_wrap(&philo->data->eat_complete);
	start_sleeping(philo);
//	mutex_lock_wrap(&philo->data->stop_simulation);
	pthread_mutex_lock(&philo->data->stop_simulation);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->stop_simulation);
//		mutex_unlock_wrap(&philo->data->stop_simulation);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_simulation);
//	mutex_unlock_wrap(&philo->data->stop_simulation);
	start_thinking(philo);
}

void	*start_simulation(void *input)
{
	t_philo	*philo;

	philo = (t_philo *) input;
	if (philo->number % 2)
		ft_usleep(250);
	routine(input);
	return (NULL);
}