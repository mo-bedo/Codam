/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbedaux <jbedaux@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/05 14:50:38 by jbedaux      #+#    #+#                 */
/*   Updated: 2022/05/08 21:51:47 by jbedaux      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

# include "../../parser/parser.h"
# include <stdbool.h>

bool	ft_unset(t_env *env, t_cmd *commands);

#endif
