/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   here_doc.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:57 by jbedaux      #+#    #+#                 */
/*   Updated: 2022/05/12 12:58:57 by jbedaux      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include "../parser/parser.h"
# include "../env/env.h"

char	*append_newline(char *line);
int		here_doc(t_env *env, t_cmd *cmd);

#endif
