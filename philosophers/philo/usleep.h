/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:54:28 by jbedaux           #+#    #+#             */
/*   Updated: 2022/02/16 16:24:09 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USLEEP_H
# define USLEEP_H

# include <sys/time.h>
# include <unistd.h>

int			ft_usleep(useconds_t sleep_time);
unsigned long	convert_to_us(const struct timeval time);

#endif
