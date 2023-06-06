/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 15:00:03 by jbedaux      #+#    #+#                 */
/*   Updated: 2022/05/16 22:09:23 by jbedaux      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../lexer/lexer.h"
# include "../parser/parser.h"

int		execute(t_env *env, t_cmd *commands);

#endif
