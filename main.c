/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/01 22:36:18 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

void	map_size(char *path, t_map *map)
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

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	map_size(path, map);
	height = 0;
	map->data = (char **)malloc((map->width + 1) * sizeof(char) * height);
	while (height < map->height)
	{
		map->data[height] = (char *)malloc((map->width) * sizeof(char));
		map->data[height] = line;
//		map->data[height][map->width] = '\0';
		height += 1;
		printf("%d\n", height);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*path = "./src/finn.xpm";
	char	*map_path;
	int		img_width;
	int		img_height;
	t_map	*map;

/*	if (argc != 2)
		exit(0);*/
	map = malloc(sizeof(t_map));
	map_path = "./map.ber";
	map_info(map_path, map);
	printf("%s\n", map->data[1]);

	mlx = mlx_init();
	mlx_win = NULL;
	mlx_win = mlx_new_window(mlx, 1280, 720, "finn");
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);
	mlx_loop(mlx);
}
