/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:27:01 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/28 14:10:25 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_error_map(char *err)
{
/*  	while(map[i])
	{
		free(map[i]);
		i++;
	}  */
	printf("%s\n", err);
	exit(1);
}

/* 
Fonction qui permet de checker si 
la carte est un rectangle
 */
void	check_rectangle(t_vars *vars)
{
	int	col;
	int	line;
	int	i;
	int y;

	i = 0;
	y = 0;
	line = nmbr_line(vars->map_file);
	while (i < line)
	{
		y = i + 1;
		if(y == line)
			break ;
		if(!check_line(vars->map[line-1]) || !check_line(vars->map[0]))
			ft_error_map( "Error : \nLa carte est mal ferme");
		col = ft_strlen(vars->map[i]);
		if (col != ft_strlen(vars->map[y]))
			ft_error_map( "ERROR :\nLa carte n'est pas un rectangle");
		if (vars->map[i][0] != 49 || vars->map[i][col - 1] != 49)
			ft_error_map( "ERROR :\nLa carte n'est pas entoure de mur");
		i++;
	}
}

/* 
Fonction qui permet de checker si 
la carte est un rectangle
 */
void check_all_data(t_vars *map,s_player *player)
{
	int	i;

	i = 0;
	init_all_data(map,player);
	if(map->collec >= 1)
		i++;
	else if (map->collec < 1)
		ft_error_map( "Error :\nNo collec");
	if(map->exit == 1)
		i++;
	else if(map->exit != 1)
		ft_error_map( "Error : \nExit missing or Too much exit");
	if(player->p == 1)
		i++;
	else if(player->p != 1)
		ft_error_map( "Error : \nNo player or too much player");
		
}

void	map_checker(t_vars *map,s_player *player)
{
	check_rectangle(map);
	check_all_data(map,player);
} 