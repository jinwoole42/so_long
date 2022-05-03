/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:52:00 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/03 16:54:41 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_size(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	map->width = ft_strlen(line) - 1;
	map->height = 0;
	while (line)
	{
		map->height += 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	map_info(char *path, t_map *map)
{
	int		fd;
	char	*line;
	int		height;
	int		i;

	fd = open(path, O_RDONLY);
	map_size(path, map);
	height = 0;
	map->data = (char **)malloc(sizeof(char *) * map->height);
	while (height < map->height)
	{
		map->data[height] = (char *)malloc((map->width + 1) * sizeof(char));
		line = get_next_line(fd);
		i = 0;
		while (10 > i)
		{
			map->data[height][i] = line[i];
			i++;
		}
		map->data[height][i] = '\0';
		height += 1;
		free(line);
	}
	close(fd);
}
