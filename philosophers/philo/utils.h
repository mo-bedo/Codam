/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:55:40 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/14 11:55:40 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <pthread.h>
# include <stdlib.h>

int		convert_string_to_int(const char *char_int);
void	*malloc_wrap(size_t size);
void	*ft_calloc(size_t count, size_t size);
void	mutex_lock_wrap(pthread_mutex_t *mutex);
void	mutex_unlock_wrap(pthread_mutex_t *mutex);

#endif
