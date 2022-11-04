/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:29:37 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/11/03 20:18:31 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char charset, char c)
{
	if (charset == c)
		return (1);
	else
		return (0);
}

static int	ft_word(char sep, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_charset(sep, str[i]) == 1 && str[i])
		i++;
	while (str[i])
	{
		j++;
		while (ft_charset(sep, str[i]) == 0 && str[i])
			i++;
		while (ft_charset(sep, str[i]) == 1 && str[i])
			i++;
	}
	return (j);
}

static char	*ft_strdup2(const char *str, char sep)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] && ft_charset(sep, str[i]) == 0)
		i++;
	res = (char *)malloc((i + 1) * sizeof (char));
	i = 0;
	if (!res)
		return (0);
	while (ft_charset(sep, str[i]) == 1 && str[i])
		i++;
	while (ft_charset(sep, str[i]) == 0 && str[i])
	{
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	split = (char **)malloc((ft_word(c, ((char *)s)) + 1) * sizeof(char *));
	if (!split)
		return (0);
	j = 0;
	i = 0;
	while (ft_charset(c, s[i]) == 1 && s[i])
		i++;
	while (s[i])
	{
		split[j] = ft_strdup2(&s[i], c);
		if (!split[j])
			return (0);
		while (ft_charset(c, s[i]) == 0 && s[i])
			i++;
		while (ft_charset(c, s[i]) == 1 && s[i])
			i++;
		j++;
	}
	split[ft_word(c, ((char *)s))] = 0;
	return (split);
}
