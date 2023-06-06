/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:38 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:38 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

int	convert_string_to_int(const char *char_int)
{
	int		ret_val;
	size_t	i;

	i = 0;
	ret_val = 0;
	while (char_int[i])
	{
		ret_val *= 10;
		ret_val += char_int[i] - 48;
		i++;
	}
	return (ret_val);
}

void	*malloc_wrap(size_t size)
{
	void	*return_pointer;

	return_pointer = malloc (size);
	if (!return_pointer)
		printf("Malloc error\n");
	return (return_pointer);
}

void	mutex_lock_wrap(pthread_mutex_t *mutex)
{
	int	error;

	error = pthread_mutex_lock(mutex);
	if (error)
		printf("Mutex lock error %i\n", error);
}

void	mutex_unlock_wrap(pthread_mutex_t *mutex)
{
	int	error;

	error = pthread_mutex_unlock(mutex);
	if (error)
		printf("Mutex unlock error %i\n", error);
}
