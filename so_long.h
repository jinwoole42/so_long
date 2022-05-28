/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:17:10 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/28 21:46:50 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include "so_long_key.h"

typedef struct	s_map {
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	char	**data;
}				t_map;

void	map_info(char *path, t_map *map);
void	exit_error(char *str);
void	name_error(int argc, char **argv);
void	shape_check(char *path);
void	data_check(t_map *map);
void	essential_check(t_map *map);
int		exit_game(t_map *map);
int		press_key(int key, t_map *map);
void	where_is_player(t_map *map);

#endif