/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:04:35 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/23 18:58:45 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[++len] != '\0')
		ret[len] = s1[len];
	while (s2[i] != '\0')
		ret[len++] = s2[i++];
	ret[len] = '\0';
	free(s1);
	return (ret);
}

char	*mon_strdup(char *s1)
{
	int		i;
	char	*new;

	i = 0;
	if (!s1[i])
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		i++;
	new = (char *)malloc(i + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		new[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
