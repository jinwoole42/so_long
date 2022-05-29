/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:50:38 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/29 16:03:32 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void real_render(t_map *map, int i, int j, int img_w, int img_h)
{
	void	*img;

	img = 0;
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

void	render(t_map *map)
{
	int	i;
	int	j;
	int		img_w;
	int		img_h;

	i = 0;
	j = 0;
	img_w = 0;
	img_h = 0;
//	img = malloc(sizeof(void *));
	real_render(map, i, j, img_w, img_h);
	printf("%d\n", map->move);
}
