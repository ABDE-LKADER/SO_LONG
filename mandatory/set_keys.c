/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/11 15:32:02 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(char **s, t_data *data)
{
	size_t	i;

	if (data)
		mlx_destroy_window(data->mlx, data->mlx_win);
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

int	destroy_notify(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (exit(0), 0);
}

void	exit_game(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

int	map_status(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (data->map.map[y][x] == 'C')
				return (1);
		}
	}
	if (ft_strchr("E", data->map.up) || ft_strchr("E", data->map.down)
		|| ft_strchr("E", data->map.right) || ft_strchr("E", data->map.left))
			return (0);
	return (1);
}
