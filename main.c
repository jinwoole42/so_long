/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/03 18:04:06 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*path = "./src/finn.xpm";
	char	*map_path;
	int		img_width;
	int		img_height;
	t_map	*map;

	check_error(argc, argv);

	map = malloc(sizeof(t_map));
	map_path = "map.ber";
	map_info(map_path, map);

	mlx = mlx_init();
	mlx_win = NULL;
	mlx_win = mlx_new_window(mlx, 1280, 720, "finn");
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);
	mlx_loop(mlx);
}
