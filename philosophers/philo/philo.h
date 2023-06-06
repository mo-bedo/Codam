/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:10 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 13:13:46 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo {
	pthread_t		thread_id;
	struct timeval	started_eating;
	struct s_data	*data;
	int				has_to_eat;
	int				number;
}					t_philo;

typedef struct s_data {
	int				number_of_philosophers;
	t_philo			*philo;
	unsigned long	die_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	think_time;
	struct timeval	simulation_t0;
	bool			stop;
	pthread_mutex_t	eat_complete;
	pthread_mutex_t	stop_simulation;
	pthread_mutex_t	*forks;
	pthread_mutex_t print;
	pthread_t		monitoring;
}					t_data;

bool	simulate_till_death(char **argv, t_data *data_philo);
bool	simulate_till_amount_eaten(char **argv, t_data *data_philo);

#endif
