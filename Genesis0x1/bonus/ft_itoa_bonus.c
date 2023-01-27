/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidqi <asidqi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:37:12 by asidqi            #+#    #+#             */
/*   Updated: 2023/01/21 21:09:00 by asidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static char	*ktebasidi(char *ret, long long int i, int size)
{
	if (i < 0)
	{
		i *= -1;
		while (--size > 0)
		{
			ret[size] = (i % 10) + 48;
			i = i / 10;
		}
		ret[size] = '-';
	}
	else
	{
		while (--size >= 0)
		{
			ret[size] = (i % 10) + 48;
			i /= 10;
		}
	}
	return (ret);
}

static int	chalmndigit(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long int	i;
	int				size;
	char			*ret;

	i = n;
	size = chalmndigit(n);
	ret = (char *)malloc ((sizeof(char) * size) + 1);
	if (!ret)
		return (0);
	ret[size] = '\0';
	ret = ktebasidi(ret, i, size);
	return (ret);
}
