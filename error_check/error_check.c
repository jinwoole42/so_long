/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:23:40 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/03 18:15:07 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t			i;
	size_t			j;
	unsigned char	*hay;
	unsigned char	*ndl;

	i = 0;
	hay = (unsigned char *)haystack;
	ndl = (unsigned char *)needle;
	if (needle[0] == '\0')
		return ((char *)hay);
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] == ndl[j])
		{
			j++;
			if (ndl[j] == '\0')
				return ((char *)&hay[i]);
		}
		i++;
	}
	return (0);
}

void	exit_error(char *str)
{
	printf("Error : %s\n", str);
	exit(1);
}

void	check_error(int argc, char **argv)
{
	if (argc != 2)
		exit_error("only one argument is OK");
	if (!(ft_strstr(argv[1], ".ber")))
		exit_error("Is that even a map file?");
}
