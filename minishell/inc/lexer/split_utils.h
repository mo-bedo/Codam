/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_utils.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: marvin <marvin@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 14:59:03 by jbedaux      #+#    #+#                 */
/*   Updated: 2022/03/23 20:47:46 by jbedaux      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_UTILS_H
# define SPLIT_UTILS_H

int	deal_with_quotation_marks(const char *str);
int	deal_with_dollar_sign(const char *str);
int	deal_with_delimiters(const char *str);
int	is_delimiter(char c);

#endif