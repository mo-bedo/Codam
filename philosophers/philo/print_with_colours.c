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

#include "print.h"
#include "philo.h"
#include <stdio.h>
#include <stdlib.h>


#include "print_colour.h"  /// REMOVE

void	print_taken_fork(t_philo *philo)
{
//	pthread_mutex_lock(&philo->data->print);

	pthread_mutex_lock(&philo->data->stop_simulation);
	if (philo->number == 1)
		red();
	if (philo->number == 2)
		green();
	if (philo->number == 3)
		yellow();
	if (philo->number == 4)
		blue();
	if (philo->number == 5)
		purple();
	if (philo->number == 6)
		cyan();


	if (!philo->data->stop)
		printf("%i %i has taken a fork\n", (int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	reset();
	pthread_mutex_unlock(&philo->data->stop_simulation);

//	pthread_mutex_unlock(&philo->data->print);
}

void	print_is_eating(t_philo *philo)
{
//	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->stop_simulation);
	if (philo->number == 1)
		red();
	if (philo->number == 2)
		green();
	if (philo->number == 3)
		yellow();
	if (philo->number == 4)
		blue();
	if (philo->number == 5)
		purple();
	if (philo->number == 6)
		cyan();


	if (!philo->data->stop)
		printf("%i %i is eating\n", (int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	reset();
	pthread_mutex_unlock(&philo->data->stop_simulation);




//	pthread_mutex_unlock(&philo->data->print);
}

void	print_is_sleeping(t_philo *philo)
{
//	pthread_mutex_lock(&philo->data->print);
	pthread_mutex_lock(&philo->data->stop_simulation);
	if (philo->number == 1)
	{
		red();
	}
	if (philo->number == 2)
	{
		green();
	}
	if (philo->number == 3)
	{
		yellow();
	}
	if (philo->number == 4)
	{
		blue();
	}
	if (philo->number == 5)
	{
		purple();
	}
	if (philo->number == 6)
	{
		cyan();
	}

	if (!philo->data->stop)
	{
		printf("%i %i is sleeping\n", (int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	}
	reset();
	pthread_mutex_unlock(&philo->data->stop_simulation);



//	pthread_mutex_unlock(&philo->data->print);
}

void	print_is_thinking(t_philo *philo)
{
//	pthread_mutex_lock(&philo->data->print);

	pthread_mutex_lock(&philo->data->stop_simulation);
	if (philo->number == 1)
		red();
	if (philo->number == 2)
		green();
	if (philo->number == 3)
		yellow();
	if (philo->number == 4)
		blue();
	if (philo->number == 5)
		purple();
	if (philo->number == 6)
		cyan();



	if (!philo->data->stop)
		printf("%i %i is thinking\n", (int) time_since_in_ms(philo->data->simulation_t0), philo->number);
	reset();
	pthread_mutex_unlock(&philo->data->stop_simulation);


//	pthread_mutex_unlock(&philo->data->print);
}

void	print_has_died(t_philo *philo)
{
//	pthread_mutex_lock(&philo->data->print);

//	pthread_mutex_lock(&philo->data->stop_simulation);
//	if (!philo->data->stop)
		printf("%i %i died\n", (int) time_since_in_ms(philo->data->simulation_t0), philo->number);

//	pthread_mutex_unlock(&philo->data->stop_simulation);

//	pthread_mutex_unlock(&philo->data->print);
//	system("leaks philo"); // remove
//	exit(0);
}