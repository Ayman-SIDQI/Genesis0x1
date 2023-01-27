/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:27:52 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/07 19:37:02 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	newline_stop(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*sd_stash(char *line)
{
	int		i;
	int		o;
	char	*ret;

	i = 0;
	o = newline_stop(line);
	if (!line[o])
	{
		free(line);
		return (NULL);
	}
	ret = malloc((ft_strlen(line) - o + 1) * sizeof(char));
	if (!ret)
	{
		free(line);
		return (NULL);
	}
	o++;
	while (line[o] != '\0')
	{
		ret[i++] = line[o++];
	}
	ret[i] = '\0';
	free(line);
	return (ret);
}

char	*readfile(int fd, char *stash)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	buff[0] = '\0';
	while (!(ft_strchr(buff, '\n')) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(stash);
			stash = NULL;
			break ;
		}
		buff[i] = '\0';
		stash = ft_strjoin(stash, buff);
		if (!stash)
			break ;
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;

	if (fd == 1 || fd == 2 || fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stash = readfile(fd, stash);
	if (!stash)
		return (NULL);
	line = mon_strdup(stash);
	stash = sd_stash(stash);
	return (line);
}
