/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwoole <indibooks@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:23:40 by jinwoole          #+#    #+#             */
/*   Updated: 2022/05/26 15:58:11 by jinwoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_error(char *str)
{
	printf("Error : %s\n", str);
	exit(1);
}

static void	your_name(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (i < 5)
		exit_error("where is g** d*** .ber?");
	if (argv[1][i - 4] != '.')
		exit_error("where is g** d*** .ber?");
	if (argv[1][i - 3] != 'b')
		exit_error("where is g** d*** .ber?");
	if (argv[1][i - 2] != 'e')
		exit_error("where is g** d*** .ber?");
	if (argv[1][i - 1] != 'r')
		exit_error("where is g** d*** .ber?");
}

void	name_error(int argc, char **argv)
{
	if (argc != 2)
		exit_error("Insert one map!!!");
	your_name(argv);
}
