/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:27:15 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/26 17:07:55 by russelenc        ###   ########.fr       */
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

void check_all_character(char *map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		if(map[i] != '1' && map[i] != '0' && map[i] != 'C' && map[i] != 'E' && map[i] != 'P')
			ft_error_map("Error \nunknown characetr in map");
		i++;
	}
}

void init_all_data(s_map *map,s_player *player, char **map_tab)
{
	int i;
	int y;
	
	i = 0;
	while(i < nmbr_line())
	{
		y = 0;
		while (map_tab[i][y])
		{
			check_all_character(map_tab[i]);
			if(map_tab[i][y] == 67)
				map->collec += 1;
			if(map_tab[i][y] == 69)
				map->exit += 1;
			if(map_tab[i][y] == 80)
			{
				player->x += i;
				player->y += y;
				player->p += 1;
			}
			y++;
		}
		i++;
	}
}



