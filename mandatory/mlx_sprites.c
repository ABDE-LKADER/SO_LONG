/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/09 21:30:40 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_exit_effects(t_data *data, int count)
{
	int			px;
	int			py;
	static int	index = E1;

	(TRUE) && (px = data->exit_x * DM, py = data->exit_y * DM);
	if (count % 299 == 0 && index < E8 && !data->map.collect)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_image_to_window(data->mlx, data->win, data->img[E8], px, py);
		mlx_put_image_to_window(data->mlx, data->win, data->img[index++], px, py);
	}
}

static void	mlx_idle_effects(t_data *data, int count)
{
	int			px;
	int			py;
	static int	index = I1;

	(TRUE) && (px = data->pos_x * DM, py = data->pos_y * DM);
	if (count % 299 == 0 && index <= I8 && !data->right && !data->up
		&& !data->left && !data->down)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_image_to_window(data->mlx, data->win, data->img[index++], px, py);
		mlx_do_sync(data->mlx);
		(index == I8) && (index = I1);
	}
}

static void	mlx_fire_effects(t_data *data, t_map *map, int count)
{
	int			x;
	int			y;
	static int	index = F1;

	if (count % 299 == 0 && index <= F8)
	{
		y = -1;
		while (map->map[++y])
		{
			x = -1;
			while (map->map[y][++x])
			{
				if (map->map[y][x] == 'C')
				{
					mlx_put_img(data, GROUND, x * DM, y * DM);
					mlx_put_image_to_window(data->mlx, data->win, data->img[index++],
						x * DM, y * DM);
					(index == F8) && (index = F1);
				}
			}
		}
	}
}

int	mlx_do_effects(void *param)
{
	t_map		*map;
	t_data		*data;
	static int	count;

	(TRUE) && (data = param, map = &data->map);
	mlx_idle_effects(data, count);
	mlx_exit_effects(data, count);
	mlx_fire_effects(data, map, count);
	return (count++);
}
