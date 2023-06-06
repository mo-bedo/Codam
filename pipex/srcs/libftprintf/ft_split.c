/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbedaux <jbedaux@codam.student.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:50:25 by jbedaux           #+#    #+#             */
/*   Updated: 2022/01/25 16:50:27 by jbedaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const *s, char c);
static char	*ft_write_str(char const *s, char c);
static void	ft_free_all(char **ret_arr);

char	**ft_split(char const *s, char c)
{
	char	**ret_arr;
	size_t	str_amount;
	size_t	i;

	if (!s)
		return (NULL);
	str_amount = ft_str_count(s, c);
	ret_arr = (char **) ft_calloc((sizeof (char *) * (str_amount + 1)), 1);
	if (!ret_arr)
		error_and_exit("malloc: ");
	i = 0;
	while (i < str_amount)
	{
		while (*s == c)
			s++;
		ret_arr[i] = ft_write_str(s, c);
		if (!ret_arr[i])
			ft_free_all(ret_arr);
		s += ft_strlen(ret_arr[i]);
		i++;
	}
	return (ret_arr);
}

static	char	*ft_write_str(char const *s, char c)
{
	size_t	i;
	char	*ret_s;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	ret_s = (char *) malloc(sizeof (char) * i + 1);
	if (!ret_s)
		return (0);
	ft_strlcpy(ret_s, s, i + 1);
	return (ret_s);
}

static int	ft_str_count(char const *s, char c)
{
	size_t	str_num;
	size_t	j;

	str_num = 0;
	j = 0;
	while (s[j])
	{
		if (((s[j + 1] == c) || (s[j + 1] == '\0')) && (s[j] != c))
			str_num++;
		j++;
	}
	return (str_num);
}

static void	ft_free_all(char **ret_arr)
{
	int	i;

	i = 0;
	while (ret_arr[i])
	{
		free(ret_arr[i]);
		i++;
	}
	free(ret_arr);
	error_and_exit("malloc: ");
}
