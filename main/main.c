/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/28 21:55:47 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_read_check(int argc, char **argv, t_map *map)
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
	int		i;
	int		j;
	int		img_w;
	int		img_h;

	i = 0;
	j = 0;
	img = malloc(sizeof(void *));
	while (i < map->height)
	{
		while(j < map->width)
		{
			if (map->data[i][j] == '0')
				img = mlx_xpm_file_to_image(map->mlx, "./src/0.xpm" ,&img_w, &img_h);
			else if (map->data[i][j] == '1')
				img = mlx_xpm_file_to_image(map->mlx, "./src/1.xpm" ,&img_w, &img_h);
			else if (map->data[i][j] == 'E')
				img = mlx_xpm_file_to_image(map->mlx, "./src/E.xpm" ,&img_w, &img_h);
			else if (map->data[i][j] == 'P')
				img = mlx_xpm_file_to_image(map->mlx, "./src/P.xpm" ,&img_w, &img_h);
			else if (map->data[i][j] == 'C')
				img = mlx_xpm_file_to_image(map->mlx, "./src/C.xpm" ,&img_w, &img_h);
			mlx_put_image_to_window(map->mlx, map->mlx_win, img, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}

int	close_map(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	free(map);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map_read_check(argc, argv, map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->width * 64, map->height * 64, "so_long");
	render(map);
	mlx_hook(map->mlx_win, 2, 0, &press_key, &map);
	mlx_hook(map->mlx_win, 17, 0, &close_map, &map);
	mlx_loop(map->mlx);
}
