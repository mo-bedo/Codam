/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_set.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:07 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:07 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_AND_SET_H
# define PARSE_AND_SET_H

# include <stdbool.h>

void	parse_argv_data(char **argv, t_data *data_philo);
bool	set_data_in_philo(t_data *data);
bool	set_simulation_time_start(t_data *data);
void	set_times_to_eat(t_data *data, char *eat_amount);

#endif
