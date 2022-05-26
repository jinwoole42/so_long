/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/26 17:15:05 by jinwoole         ###   ########.fr       */
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

int	key_press(int keycode, t_param *param)
{
	int a = 0;

	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map_read_check(argc, argv, map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->width * 64, map->height * 64, "so_long");
	mlx_hook(mlx->win, X_EVENT_KEY_RELEASE, 0, &key_press, &)
	render(map);
	mlx_loop(map->mlx);
}
