/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/29 16:05:19 by jinwoole         ###   ########.fr       */
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
	map->move = 0;
	map->collect = 0;
	map->player_c = 0;
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
	mlx_hook(map->mlx_win, 2, 0, &press_key, map);
	mlx_hook(map->mlx_win, 17, 0, &close_map, map);
	mlx_loop(map->mlx);
}
