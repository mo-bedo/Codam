/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:28 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 16:24:09 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGV_H
# define PARSE_ARGV_H

# include <stdbool.h>

bool	is_argv_invalid(int argc, char **argv);
bool	is_not_numeric(char c);
bool	check_argv(int argc, char **argv, t_data *data_philo);

#endif
