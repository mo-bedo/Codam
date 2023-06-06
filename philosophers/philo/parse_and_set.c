/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:04 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 13:07:04 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "time_utils.h"
#include "utils.h"
#include <stdio.h>
#include <stdbool.h>
//
//static void	get_time_to_think(t_data *data)
//{
//	unsigned long	die;
//	unsigned long	eat;
//	unsigned long	sleep;
//
//	sleep = convert_to_ms(data->sleep_time);
//	eat = convert_to_ms(data->eat_time);
//	die = convert_to_ms(data->die_time);
//	if (die - (sleep + eat) > 40)
//		data->think_time = (die - (eat + sleep)) / 2;
//	else
//		data->think_time = 0;
//}

void	parse_argv_data(char **argv, t_data *data_philo)
{
	data_philo->number_of_philosophers = convert_string_to_int(argv[1]);
	data_philo->die_time = (unsigned long) convert_string_to_int(argv[2]);
	data_philo->eat_time = (unsigned long) convert_string_to_int(argv[3]);
	data_philo->sleep_time = (unsigned long) convert_string_to_int(argv[4]);
//	get_time_to_think(data_philo);
}

//	Return true if an error occured. Else returns false.
bool	set_data_in_philo(t_data *data)
{
	int	i;
	int	j;

	data->philo = (t_philo *) malloc_wrap \
					(sizeof (t_philo) * data->number_of_philosophers);
	if (!data->philo)
		return (true);
	j = 1;
	i = 0;
	data->stop = false;
	while (i < data->number_of_philosophers)
	{
		data->philo[i].data = data;
		data->philo[i++].number = j++;
	}
	return (false);
}

//	Return true if an error occured. Else returns false.
bool	set_simulation_time_start(t_data *data)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
	{
		printf("Error with gettimeofday.\n");
		return (true);
	}
	data->simulation_t0 = current_time;
	return (false);
}

void	set_times_to_eat(t_data *data, char *eat_amount)
{
	int	i;
	int	times_to_eat;

	i = 0;
	times_to_eat = convert_string_to_int(eat_amount);
	while (i < data->number_of_philosophers)
	{
		data->philo[i].has_to_eat = times_to_eat;
		i++;
	}
}
