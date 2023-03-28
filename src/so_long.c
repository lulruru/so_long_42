/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:50 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/28 14:49:42 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


/* 
Fonction d'initalisation de la structure
 */
void init_struct(s_player *player, char *map_file, t_vars	*vars)
{
	vars->exit = 0;
	vars->collec = 0;
	player->x = 0;
	player->y = 0;
	player->p = 0;
	vars->map_file = map_file;
	vars->collec = 0;
	vars->movement = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = nmbr_line(map_file);
}

int main(int ac, char **av)
{
	int len;
	char **map;
	int	i;
	i = 0;
	s_player player;
	t_vars	vars;
	if(ac < 2)
		return(0);
	check_format(av[1]);
	len = nmbr_line(av[1]);
	vars.map = gen_map(len, &vars, av[1]);
	init_struct(&player, av[1], &vars);
	map_checker(&vars, &player);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,vars.win_w * 32, vars.win_h * 32, "so_long");
	gen_win(vars.map, &vars);
	mlx_loop(vars.mlx);
	while(i < len)
	{
		printf("%s\n", vars.map[i]);
		i++;
	}
	return(0);
}