/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:03:42 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/10 20:00:27 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*char_path = "./src/finn.xpm";
	char	*map_path;
	int		img_width;
	int		img_height;
	t_map	*map;

	map_path = argv[1];
	name_error(argc, argv);
	shape_check(map_path);
	map = malloc(sizeof(t_map));
	map_info(map_path, map);

	int i;

	i = 0;
	printf("%d\n", map->width);
	printf("%d\n", map->height);
	while (i < map->height)
	{
		printf("%s\n", map->data[i]);
		i++;
	}

	data_check(map);

	
	mlx = mlx_init();
	mlx_win = NULL;
	mlx_win = mlx_new_window(mlx, 1280, 720, "finn");
	img = mlx_xpm_file_to_image(mlx, char_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, 100, 100);
	mlx_loop(mlx);
}
