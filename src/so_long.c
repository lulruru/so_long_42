/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:50 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/28 13:39:15 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


/* 
Fonction d'initalisation de la structure
 */
void init_struct(s_map *map, s_player *player, char *map_file, t_vars	*vars, char **map_tab)
{
	map->exit = 0;
	map->collec = 0;
	player->x = 0;
	player->y = 0;
	player->p = 0;
	vars->collect = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(map_tab[0]);
	vars->win_h = nmbr_line();
}




int main(int ac, char **av)
{
	int len;
	char **map;
	int	i;
	i = 0;
	s_map map_data;
	s_player player;
	t_vars	vars;
	if(ac < 2)
		return(0);
	check_format(av[1]);
	len = nmbr_line();
	map = gen_map(len, &map_data);
	init_struct(&map_data, &player, av[1], &vars, map);
/* 	map_checker(&map_data, &player, map); */
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, \
				1000, 1000, "So-Long");
/* 	vars.img = mlx_xpm_file_to_image(vars.mlx, img, &img_w, &img_h);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0); */
	gen_win(map.map, &vars);
	mlx_loop(vars.mlx);
	while(i < len)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return(0);
}