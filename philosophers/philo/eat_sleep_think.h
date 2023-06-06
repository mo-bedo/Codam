/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:30 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:30 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EAT_SLEEP_THINK_H
# define EAT_SLEEP_THINK_H

# include "philo.h"

void	start_sleeping(t_philo *philo);
void	start_eating_last_philo(t_philo *philo);
void	start_eating(t_philo *philo);
void	start_thinking(t_philo *philo);

#endif
