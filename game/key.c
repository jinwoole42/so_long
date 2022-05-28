/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:51:35 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/28 21:52:55 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_map *map)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		printf("%s\n", map->data[1]);
		i++;
	}
}

void	move_a(t_map *map)
{
//	int	i;

//	i = 0;
	printf("%d\n", map->player_x);
	printf("%d\n", map->player_y);
}

void	move_s(t_map *map)
{
//	int	i;

//	i = 0;
	printf("%d\n", map->player_x);
	printf("%d\n", map->player_y);
}

void	move_d(t_map *map)
{
//	int	i;

//	i = 0;
	printf("%d\n", map->player_x);
	printf("%d\n", map->player_y);
}

int	press_key(int key_code, t_map *map)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move_w(map);
	if (key_code == KEY_A)
		move_a(map);
	if (key_code == KEY_S)
		move_s(map);
	if (key_code == KEY_D)
		move_d(map);
	return (0);
}