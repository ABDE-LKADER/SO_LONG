/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 11:08:45 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_put_exit(t_data *data, int set, int x, int y)
{
	void	*img;
	char	*path;

	(set == 1) && (path = EXIT1);
	(set == 2) && (path = EXIT2);
	(set == 3) && (path = EXIT3);
	(set == 4) && (path = EXIT4);
	(set == 5) && (path = EXIT5);
	(set == 6) && (path = EXIT6);
	(set == 7) && (path = EXIT7);
	(set == 8) && (path = EXIT8);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_destroy_image(data->mlx, img);
}

void	mlx_exit_effects(t_data *data, int count)
{
	int			px;
	int			py;
	static int	set;

	(TRUE) && (px = data->exit_x * DM, py = data->exit_y * DM);
	if (count % 299 == 0 && ++set <= 8 && !data->map.collect)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_img(data, EXIT8, px, py);
		mlx_put_exit(data, set, px, py);
	}
}
