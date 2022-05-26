/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/26 16:45:10 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_read_check(int argc, char **argv, t_map *map)
{
	char	*map_path;

	map_path = argv[1];
	name_error(argc, argv);
	shape_check(map_path);
	map_info(map_path, map);
	data_check(map);
}

void	render(t_map *map)
{
	void	*img;
	int		x;
	int		y;
	int		img_w;
	int		img_h;

	x = 0;
	y = 0;
	img = malloc(sizeof(void *));
	while (x < map->height)
	{
		while(y < map->width)
		{
			if (map->data[x][y] == '0')
				img = mlx_xpm_file_to_image(map->mlx, "./src/0.xpm" ,&img_w, &img_h);
			else if (map->data[x][y] == '1')
				img = mlx_xpm_file_to_image(map->mlx, "./src/1.xpm" ,&img_w, &img_h);
			else if (map->data[x][y] == 'E')
				img = mlx_xpm_file_to_image(map->mlx, "./src/E.xpm" ,&img_w, &img_h);
			else if (map->data[x][y] == 'P')
				img = mlx_xpm_file_to_image(map->mlx, "./src/P.xpm" ,&img_w, &img_h);
			else if (map->data[x][y] == 'C')
				img = mlx_xpm_file_to_image(map->mlx, "./src/C.xpm" ,&img_w, &img_h);
			mlx_put_image_to_window(map->mlx, map->mlx_win, img, y * 64, x * 64);
			y++;
		}
		y = 0;
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map_read_check(argc, argv, map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->width * 64, map->height * 64, "so_long");
	render(map);

	mlx_loop(map->mlx);
}
