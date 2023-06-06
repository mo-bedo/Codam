/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:25 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:25 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "philo.h"

void	print_taken_fork(t_philo *philo);
void	print_is_eating(t_philo *philo);
void	print_is_sleeping(t_philo *philo);
void	print_is_thinking(t_philo *philo);
void	print_has_died(t_philo *philo);

#endif
