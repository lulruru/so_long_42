/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:22:24 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/30 17:58:23 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdlib.h>	
# include <unistd.h>
# include <fcntl.h>
# include  <stdio.h>
#include "../mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

typedef struct s_player{
	int y;
	int x;
	int p;
} s_player;

typedef struct s_vars {
	void	*mlx;
	void	*img;
	void	*win;
	int		win_w;
	int		win_h;
	int		x_p;
	int		y_p;
	char	*map_file;
	int		move;
	char	**map;
	int		exit;
	int		collec;
	int		p;
}	t_vars;


/* 			GET_NEXT_LINE		 */
int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_readfd(int fd, char *buffle);
char	*cpyline(char *line);
char	*savenext(char *buffle);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_free(char *s);
int		test(char *s);

/* 				MAP_UTILS		*/
int		check_line(char *str);
void    check_rectangle(t_vars **vars);
char	**gen_map(int len, t_vars *map, char *fmap);
int		nmbr_line(char *fmap);
void	check_all_data(t_vars **map);
void	init_all_data(t_vars *vars);
void	ft_error_map(t_vars ***vars, char *err);
void	map_checker(t_vars *map);
void	check_format(char *map_file);

/* 				MLX_UTILS		*/
void	gen_win(t_vars *vars);
int		ft_exit(t_vars ***vars);

/* 				KEY_HOOK		 */
int ft_key_hook(int keycode, t_vars *vars);
void	go_right(t_vars **v);
void	go_left(t_vars **v);
void	go_up(t_vars **v);
void	go_down(t_vars **v);
void	print_move(t_vars ***v);
int 	anime(t_vars *v);

# endif