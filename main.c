/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/04/27 16:38:47 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>

void	read_map(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	map->height = 0;
	map->width = ft_strlen(line) - 1;
	map->map_data = ft_strdup(line);
	free(line);
	while (line)
	{
		map->height++;
		line = get_next_line(fd);
		if (line)
		{
			map->map_data = ft_strjoin(map->map_data, line);
		}
	}
	close(fd);
	printf("%s\n", map->map_data);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*path = argv[1];
	int		img_width;
	int		img_height;
	t_map	map;

	if (argc != 2)
		exit(0);
	read_map(path, &map);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 720, "finn");
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	printf("%d\n", img_width);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);
	mlx_loop(mlx);
}
