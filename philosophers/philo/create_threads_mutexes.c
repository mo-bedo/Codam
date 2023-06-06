/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_mutexes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:47 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 12:05:04 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "monitoring.h"
#include "start_simulation.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>

//	Returns true if an error occurs. Else returns false
static bool	pthread_create_wrap(t_philo *philo)
{
	if (philo->data->number_of_philosophers == 1)
	{
		if (pthread_create(&philo->thread_id, NULL, \
			start_simulation_one, (void *) philo))
		{
			printf("Error: pthread_create philo thread\n");
			return (true);
		}
	}
	else
	{
		if (pthread_create(&philo->thread_id, NULL, \
			start_simulation, (void *) philo))
		{
			printf("Error: pthread_create philo thread\n");
			return (true);
		}
	}
	return (false);
}

//	Returns true if an error occurs. Else returns false
bool	create_philothread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philo[i].started_eating.tv_usec = 0;
		if (pthread_create_wrap(&data->philo[i]))
			return (true);
		i++;
	}
	return (false);
}

//	Returns true if error occured. Else returns false.
bool	initialise_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->stop_simulation, NULL) || \
		pthread_mutex_init(&data->eat_complete, NULL) || pthread_mutex_init(&data->print, NULL))
	{
		printf("Mutex: initialising error\n");
		return (true);
	}
	data->forks = (pthread_mutex_t *) malloc_wrap (sizeof (pthread_mutex_t) * \
											data->number_of_philosophers);
	if (!data->forks)
		return (true);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			printf("Mutex: initialising fork error\n");
			return (true);
		}
		i++;
	}
	return (false);
}

pthread_t	create_monitoring_till_times_eaten(t_data *data)
{
	pthread_t	monitoring;

	if (pthread_create(&monitoring, NULL, start_monitoring_till_times_eaten, \
											(void *) data))
	{
		printf("Error: pthread_create monitoring thread\n");
		return (NULL);
	}
	return (monitoring);
}

pthread_t	create_monitoring_till_death(t_data *data)
{
	pthread_t	monitoring;


	if (pthread_create(&monitoring, NULL, start_monitoring_till_death, \
											(void *) data))
	{
		printf("Error: pthread_create monitoring thread\n");
		return (NULL);
	}
	return (monitoring);
}
