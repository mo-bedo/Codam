/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:35 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:35 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_UTILS_H
# define TIME_UTILS_H

# include "philo.h"
# include <sys/time.h>

unsigned long		convert_to_us(const struct timeval time);
unsigned long			convert_to_ms(const struct timeval time);
unsigned long			time_since_in_ms(const struct timeval since);
struct timeval	get_time_to(char *time_to);
bool			has_time_to_die_expired(t_philo *philo);

#endif
