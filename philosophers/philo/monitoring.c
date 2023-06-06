/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:28 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:54:28 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usleep.h"
#include "philo.h"
#include "time_utils.h"
#include "utils.h"
#include "print.h"
#include <stdbool.h>

static bool	has_philo_died(t_philo *philo)
{
	if (has_time_to_die_expired(philo))
	{
		mutex_lock_wrap(&philo->data->print);
		mutex_lock_wrap(&philo->data->stop_simulation);
		print_has_died(philo);
		philo->data->stop = true;
		mutex_unlock_wrap(&philo->data->stop_simulation);
		return (true);
	}
	else
		return (false);
}

static bool	has_philos_eaten_enough(t_data *data)
{
	int	i;
	int	eat_complete_countdown;

	eat_complete_countdown = data->number_of_philosophers;
	i = 0;
	while (i < data->number_of_philosophers)
	{
		mutex_lock_wrap(&data->eat_complete);
		if (data->philo[i].has_to_eat <= 0)
			eat_complete_countdown--;
		mutex_unlock_wrap(&data->eat_complete);
		i++;
	}
	if (eat_complete_countdown)
		return (false);
	else
	{
		mutex_lock_wrap(&data->stop_simulation);
		data->stop = true;
		mutex_unlock_wrap(&data->stop_simulation);
		return (true);
	}
}

void	*start_monitoring_till_times_eaten(void *input)
{
	t_data	*data;
	int		i;
	int		end;

	end = 1;
	data = (t_data *) input;
	while (end)
	{
		if (has_philos_eaten_enough(data))
			break ;
		i = 0;
		while (i < data->number_of_philosophers)
		{
			if (has_philo_died(&data->philo[i]))
			{
				end = 0;
				break ;
			}
			i++;
		}
		ft_usleep(500);
	}
	return (input);
}

void	*start_monitoring_till_death(void *input)
{
	t_data	*data;

	int		i;
	int		end;

	end = 1;
	data = (t_data *) input;
	while (end)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			if (has_philo_died(&data->philo[i]))
			{
				end = 0;
				break ;
			}
			i++;
		}
		ft_usleep(500);
	}
	mutex_unlock_wrap(&data->print);
	return (data);
}
