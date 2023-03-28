/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:22:24 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/28 14:31:17 by russelenc        ###   ########.fr       */
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
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	char			*map_file;
	int				movement;
	char			**map;
	int				exit;
	int				collec;
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
void    check_rectangle(t_vars *vars);
char	**gen_map(int len, t_vars *map, char *fmap);
int		nmbr_line(char *fmap);
void	check_all_data(t_vars *map,s_player *player);
void	init_all_data(t_vars *map,s_player *player);
void	ft_error_map(char *err);
void	map_checker(t_vars *map,s_player *player);
void	check_format(char *map_file);

/* 				MLX_UTILS		*/
void	gen_win(char **map,t_vars *vars);


# endif