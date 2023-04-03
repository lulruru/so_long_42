/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:50 by russelenc         #+#    #+#             */
/*   Updated: 2023/04/03 11:08:34 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


/* 
Fonction d'initalisation de la structure
 */
void init_struct(char *map_file, t_vars	*vars)
{
	vars->exit = 0;
	vars->collec = 0;
	vars->x_p = 0;
	vars->y_p = 0;
	vars->p = 0;
	vars->map_file = map_file;
	vars->collec = 0;
	vars->move = 0;
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = nmbr_line(map_file);
}
int	ft_exit(t_vars ***vars)
{
	int	i;

	i = 0;
	while((**vars)->map[i])
	{
		free((**vars)->map[i]);
		i++;
	}
	free((**vars)->map);
	mlx_destroy_window((**vars)->mlx, (**vars)->win);
	exit(1);
	return (0);
}

void print_move(t_vars ***v)
{
	(**v)->move++;
	printf(" Move : %d\n",(**v)->move);
}
int	ft_close(t_vars *vars)
{
	int	i;

	i = 0;
	while(vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (0);
}

int main(int ac, char **av)
{
	int len;
	t_vars	vars;
	
	if(ac < 2)
		return(0);
	check_format(av[1]);
	len = nmbr_line(av[1]);
	vars.map = gen_map(len, &vars, av[1]);
	init_struct(av[1], &vars);
	map_checker(&vars);
	ft_floodfill(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,vars.win_w * 32, vars.win_h * 32, "so_long");
	gen_win(&vars);
	mlx_hook(vars.win, 2, (1L << 0), ft_key_hook, &vars);
	mlx_hook(vars.win, 17, (1L << 0), ft_close, &vars);
	mlx_loop_hook(vars.mlx, anime, &vars);
	mlx_loop(vars.mlx);
	return(0);
}