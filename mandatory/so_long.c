/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 17:44:39 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_do_effects(t_data *data, void *param)
{
	;
}

static void	mlx_game_render(t_data *data)
{
	int		y;
	int		x;
	int		px;
	int		py;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			(TRUE) && (px = x * DM, py = y * DM);
			mlx_image_to_window(data->mlx, data->img.ground[GR], px, py);
			if (data->map.map[y][x] == '1')
				set_wall(data, data->img, x, y);
			else if (data->map.map[y][x] == 'E')
				mlx_image_to_window(data->mlx, data->img.exit[EX], px, py);
			else if (data->map.map[y][x] == 'P')
				mlx_image_to_window(data->mlx, data->img.player, px, py);
			else if (data->map.map[y][x] == 'C')
				mlx_image_to_window(data->mlx, data->img.collect, px, py);
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	mlx_parce_input(ac, av, &data);
	data.mlx = mlx_init(data.map.width * DM,
			data.map.height * DM, TILTEL, false);
	if (!data.mlx)
		return (cleanup(&data.leak), EXIT_FAILURE);
	mlx_init_img(&data);
	mlx_key_hook(data.mlx, mlx_move_player, &data);
	mlx_loop_hook(data.mlx, mlx_do_effects, &data);
	mlx_game_render(&data);
	mlx_loop(data.mlx);
}
