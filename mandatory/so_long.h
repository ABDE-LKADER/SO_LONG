/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 17:44:07 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H 
# define SO_LONG_H

# include "mylib.h"
# include <fcntl.h>
# include <math.h>
# include <MLX42.h>

///////////////// HEAP_CLEANER /////////////////

typedef struct s_allocate
{
	void				*block;
	struct s_allocate	*next;
}						t_allocate;

void	cleanup(t_allocate **collec);
void	*allocate(t_allocate **collec, size_t count, size_t size);

///////////////// SO_LONG /////////////////

typedef struct s_map
{
	int				len;
	int				exit;
	int				width;
	int				height;
	int				player;
	int				collect;
	int				unwanted;
	char			up;
	char			down;
	char			left;
	char			right;
	char			**map;
	char			**flood;
}					t_map;

typedef struct s_img
{
	mlx_image_t		*player;
	mlx_image_t		*collect;
	mlx_image_t		*exit[8];
	mlx_image_t		*wall[12];
	mlx_image_t		*ground[4];
}				t_img;

typedef struct s_data
{
	mlx_t			*mlx;
	t_map			map;
	t_img			img;
	int				moves;
	int				pos_x;
	int				pos_y;
	int				exit_x;
	int				exit_y;
	int				timer;
	int				count;
	t_allocate		*leak;
}					t_data;

# define TILTEL "so_long"

# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define RED "\033[1;31m"
# define RST "\033[0m"

# define TRUE 1
# define FALSE 0
# define DM 60

# define WA 0
# define W0 1
# define W2 2
# define WE 3
# define WL 4
# define WR 5
# define WU 6
# define WD 7
# define DL 8
# define UL 9
# define DR 10
# define UR 11

# define EX 0
# define E0 1
# define E1 2
# define E2 3
# define E3 4
# define E4 5
# define E5 6
# define E6 7

# define GR 0
# define G2 2
# define G3 3

# define WALL "textures/wall.png"
# define WALL0 "textures/wall0.png"
# define WALL2 "textures/wall2.png"
# define WALL_E "textures/wall_e.png"
# define WALL_L "textures/wall_l.png"
# define WALL_R "textures/wall_r.png"
# define WALL_U "textures/wall_u.png"
# define WALL_D "textures/wall_d.png"
# define WALL_DL "textures/wall_dl.png"
# define WALL_UL "textures/wall_ul.png"
# define WALL_DR "textures/wall_dr.png"
# define WALL_UR "textures/wall_ur.png"

# define EXIT "textures/exit.png"
# define EXIT0 "textures/exit0.png"
# define EXIT1 "textures/exit1.png"
# define EXIT2 "textures/exit2.png"
# define EXIT3 "textures/exit3.png"
# define EXIT4 "textures/exit4.png"
# define EXIT5 "textures/exit5.png"
# define EXIT6 "textures/exit6.png"

# define GROUND "textures/ground.png"
# define GROUND2 "textures/ground2.png"
# define GROUND3 "textures/ground3.png"

# define PLAYER "textures/player.png"
# define COLLECT "textures/collect.png"

void	init_data(t_data *data);
void	exit_game(t_data *data);
void	mlx_init_img(t_data *data);
void	mlx_message_error(int set);
int		map_status(t_map map, int key);
int		checker_set(char **map, char set);
void	cleaning(t_allocate **leak, t_data *data);
void	flood_fill(char **map, int pos_x, int pos_y);
void	set_exit(t_data *data, t_img img, int x, int y);
void	mlx_parce_input(int ac, char **av, t_data *data);
void	mlx_move_player(mlx_key_data_t key, void *param);
void	set_wall(t_data *data, t_img img, int x, int y);

#endif
