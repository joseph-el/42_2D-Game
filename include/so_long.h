/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:29:48 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/22 22:21:32 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../tools/tools.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define SUCCESS 1
# define FAILURE 0
# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define KEY_W 13
# define KEY_EXIT 53
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"

typedef struct s_data
{
	char	**map;
	char	**c_map;
	int		fd;
	int		key;
	int		t_key;
	int		pd;
	int		p_exit;
	int		p_id;
	int		p_rw;
	int		t_p;
	int		lenght;
	int		arr;
	int		rw;
	int		id;
	bool	vr;
}			t_data;

typedef struct s_graphic
{
	void	*mlx;
	void	*window;
	void	*background;
	void	*pd;
	void	*key;
	void	*unlock;
	void	*lock;
	void	*wall;
	int		t_key;
	int		i_size;
	void	*enemy;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*r_pd;
	void	*sc1;
	void	*sc2;
	void	*sc3;
	void	*sc4;
	bool	c_pd;
	t_data	*data;
}			t_grp;

void		get_path_a(t_grp *ap);
int			ft_close(t_grp *ap);
void		moving(int key, t_grp *ap);
void		clear_arr(char **error);
void		path(char **line, int id, int rw, t_data *ap);
void		get_path_b(t_grp *ap);
void		rip_program(t_grp *ap, bool check);
void		free_memory(t_grp **ap);
void		get_path_b1(t_grp *ap);
void		initialisation(t_grp *ap);
int			fill_data_dup(t_data *ap, char target, int *id, int *rw);
int			key_hook_a(int keycode, t_grp *ap);
int			showing_img(t_grp *ap);
int			signifies(int gnl, t_data *ap);
int			add_matrix(t_data *ap);

int			search(char *str, int targeet, unsigned int len);

int			detecting(t_data *ap);
int			maps(char *args, t_data *ap);
void		level_score(t_grp *ap, int moved);

void		moving(int key, t_grp *ap);
void		display(t_grp *ap);
int			showing_img(t_grp *ap);

int			key_hook_b(int keycode, t_grp *ap);
int			exit_program(t_grp *ap);

#endif