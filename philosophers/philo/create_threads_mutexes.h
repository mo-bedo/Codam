/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_mutexes.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:53 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 11:15:25 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_THREADS_MUTEXES_H
# define CREATE_THREADS_MUTEXES_H

# include "philo.h"
# include <pthread.h>
# include <stdbool.h>

bool		create_philothread(t_data *data);
bool		initialise_mutexes(t_data *data);
pthread_t	create_monitoring_till_death(t_data *data);
pthread_t	create_monitoring_till_times_eaten(t_data *data);

#endif
