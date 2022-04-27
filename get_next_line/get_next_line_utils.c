/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:58:36 by jinwoole          #+#    #+#             */
/*   Updated: 2022/04/27 16:42:11 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*get_line(char *backup_str)
{
	int		i;
	char	*str;

	i = 0;
	if (backup_str[i] == 0)
		return (0);
	while (backup_str[i] && backup_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (str == 0)
		return (0);
	i = 0;
	while (backup_str[i] && backup_str[i] != '\n')
	{
		str[i] = backup_str[i];
		i++;
	}
	if (backup_str[i] == '\n')
	{
		str[i] = backup_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_backup_str(char *backup_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup_str[i] && backup_str[i] != '\n')
		i++;
	if (backup_str[i] == 0)
	{
		free(backup_str);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup_str) - i + 1));
	if (str == 0)
		return (0);
	i++;
	j = 0;
	while (backup_str[i])
		str[j++] = backup_str[i++];
	str[j] = '\0';
	free(backup_str);
	return (str);
}
