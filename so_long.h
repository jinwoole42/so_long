/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:17:10 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/10 15:37:18 by jinwoole         ###   ########.fr       */
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

typedef struct	s_map {
	int		height;
	int		width;
	char	**data;
}				t_map;

void	map_info(char *path, t_map *map);
void	exit_error(char *str);
void	name_error(int argc, char **argv);
void	shape_check(char *path);
void	data_check(t_map *map);

#endif