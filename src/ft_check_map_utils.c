/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:27:15 by russelenc         #+#    #+#             */
/*   Updated: 2023/05/04 11:45:34 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


/* 
Fonction qui permet de checker 
si ma ligne du bas et du haut sont fermer
*/
int check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 49)
			return (0);
		i++;
	}
	return (1);
}

void check_all_character(char *map, t_vars **vars)
{
	int	i;

	i = 0;
	while(map[i])
	{
		if(map[i] != '1' && map[i] != '0' && map[i] != 'C' && map[i] != 'E' && map[i] != 'P')
			ft_error_map(&vars, "Error \nunknown character in map");
		i++;
	}
}

void init_all_data(t_vars *vars)
{
	int i;
	int y;
	
	i = 0;
	while(i < nmbr_line(vars->map))
	{
		y = 0;
		while (vars->map[i][y])
		{
			check_all_character(vars->map[i], &vars);
			if(vars->map[i][y] == 67)
				vars->collec += 1;
			if(vars->map[i][y] == 69)
				vars->exit += 1;
			if(vars->map[i][y] == 80)
			{
				vars->p += 1;
			}
			y++;
		}
		i++;
	}
}







