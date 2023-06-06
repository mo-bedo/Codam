/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parameter_expansion.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:53 by jbedaux      #+#    #+#                 */
/*   Updated: 2022/05/12 13:14:28 by jbedaux      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMETER_EXPANSION_H
# define PARAMETER_EXPANSION_H

# include "../parser/parser.h"

char	*handle_parameter_expansion(t_env *env, char *src);

#endif
