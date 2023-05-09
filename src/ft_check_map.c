/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:27:01 by russelenc         #+#    #+#             */
/*   Updated: 2023/05/04 11:46:27 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_error_map(t_vars ***vars, char *err)
{
	int	i;

	i = 0;
	
  	while((**vars)->map[i])
	{
		free((**vars)->map[i]);
		i++;
	} 
	free((**vars)->map);
	printf("%s\n", err);
	exit(1);
}

/* 
Fonction qui permet de checker si 
la carte est un rectangle
 */
void	check_rectangle(t_vars **vars)
{
	int	col;
	int	line;
	int	i;
	int y;

	i = 0;
	y = 0;
	line = nmbr_line((*vars)->map);
	while (i < line)
	{
		y = i + 1;
		if(y == line)
			break ;
		if(!check_line((*vars)->map[line-1]) || !check_line((*vars)->map[0]))
			ft_error_map(&vars, "ERROR :\nLa carte est mal ferme");
		col = ft_strlen((*vars)->map[i]);
		if (col != ft_strlen((*vars)->map[y]))
			ft_error_map(&vars, "ERROR :\nLa carte n'est pas un rectangle");
		if ((*vars)->map[i][0] != 49 || (*vars)->map[i][col - 1] != 49)
			ft_error_map(&vars, "ERROR :\nLa carte n'est pas entoure de mur");
		i++;
	}
}

/* 
Fonction qui permet de checker si 
la carte est un rectangle
 */
void check_all_data(t_vars **map)
{
	int	i;

	i = 0;
	init_all_data((*map));
	if((*map)->collec >= 1)
		i++;
	else if ((*map)->collec < 1)
		ft_error_map(&map, "Error :\nNo collec");
	if((*map)->exit == 1)
		i++;
	else if((*map)->exit != 1)
		ft_error_map(&map, "Error : \nExit missing or Too much exit");
	if((*map)->p == 1)
		i++;
	else if((*map)->p != 1)
		ft_error_map(&map, "Error : \nNo player or too much player");
		
}

void	map_checker(t_vars *map)
{
	char **tmp;
	check_rectangle(&map);
	check_all_data(&map);
	tmp = cpymap(&map, tmp);
	ft_floodfill(map, tmp);
} 