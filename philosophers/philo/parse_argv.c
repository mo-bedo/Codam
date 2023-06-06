/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:28 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 16:24:09 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "philo.h"
#include <stdbool.h>
#include <stdio.h>

bool	is_not_numeric(char c)
{
	if (c < 48 || c > 57)
		return (true);
	else
		return (false);
}

// Returs true if an error occured. Else return false
bool	is_argv_invalid(int argc, char **argv)
{
	int	i;

	if (convert_string_to_int(argv[1]) <= 0)
	{
		printf("Invalid number of philosophers (0 or less).\n");
		return (true);
	}
	while (--argc)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (is_not_numeric(argv[argc][i]))
			{
				printf("Invalid input (only (positive) numbers allowed).\n");
				return (true);
			}
			i++;
		}
	}
	return (false);
}

// Returs true if an error occured. Else return false
bool	check_argv(int argc, char **argv, t_data *data_philo)
{
	bool	error;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid number of arguments\n");
		return (true);
	}
	if (is_argv_invalid(argc, argv))
		return (true);
	if (argc == 5)
		error = simulate_till_death(argv, data_philo);
	else
		error = simulate_till_amount_eaten(argv, data_philo);
	return (error);
}
