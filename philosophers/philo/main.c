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

#include "philo.h"
#include "parse_argv.h"
#include "parse_and_set.h"
#include "create_threads_mutexes.h"
#include "monitoring.h"
#include <stdio.h>
#include <stdbool.h>

//	Return true if an error occured. Else returns false.
bool	simulate_till_death(char **argv, t_data *data_philo)
{
	parse_argv_data(argv, data_philo);
	if (initialise_mutexes(data_philo))
		return (true);
	if (set_data_in_philo(data_philo))
		return (true);
	if (set_simulation_time_start(data_philo))
		return (true);
	if (create_philothread(data_philo))
		return (true);
//	start_monitoring_till_death(data_philo);
	data_philo->monitoring = create_monitoring_till_death(data_philo);
	if (!data_philo->monitoring)
		return (true);
	return (false);
}

//	Return true if an error occured. Else returns false.
bool	simulate_till_amount_eaten(char **argv, t_data *data_philo)
{
	parse_argv_data(argv, data_philo);
	if (initialise_mutexes(data_philo))
		return (true);
	if (set_data_in_philo(data_philo))
		return (true);
	set_times_to_eat(data_philo, argv[5]);
	if (set_simulation_time_start(data_philo))
		return (true);
	if (create_philothread(data_philo))
		return (true);
	data_philo->monitoring = create_monitoring_till_times_eaten(data_philo);
	if (!data_philo->monitoring)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_data	data_philo;
	int		i;

	if (check_argv(argc, argv, &data_philo))
		return (1);
	i = 0;
	while (i < data_philo.number_of_philosophers)
	{
		if (pthread_join(data_philo.philo[i].thread_id, NULL))
		{
			printf("Error: pthread_detach philosopher\n");
			return (1);
		}
		i++;
	}
//	while (i < data_philo.number_of_philosophers)
//	{
//		if (pthread_detach(data_philo.philo[i].thread_id))
//		{
//			printf("Error: pthread_detach philosopher\n");
//			return (1);
//		}
//		i++;
//	}
	if (pthread_join(data_philo.monitoring, NULL))
	{
		printf("Error: pthread_join monitoring\n");
		return (1);
	}
	return (0);
}
