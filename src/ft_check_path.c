/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:45:28 by russelenc         #+#    #+#             */
/*   Updated: 2023/04/03 11:12:03 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void find_player_position(char **map, int *x_p, int *y_p)
{
	int	i;
	int	y;

	i = -1;
	while(map[++i])
	{
		y = -1;
		while(map[i][++y])
		{
			if(map[i][y] == 'P')
			{
				*x_p = y;
				*y_p = i;
				break ;
			}
		}
	}
}

void flood_fill(char **map, int row, int col)
{
	if (row < 0 || col < 0 || row >= 5|| col >= 14)
        return;
	if(map[row][col] == '2' || map[row][col] == '1')
		return ;
	map[row][col] = '2';
	flood_fill(map, row - 1, col);
    flood_fill(map, row + 1, col);
    flood_fill(map, row, col - 1);
    flood_fill(map, row, col + 1);
}
void print_floodfill(char **map)
{
	int	i = 0;
	
	while(i < 6 )
	{
		printf("%s\n",map[i]);
		i++;
	}
}
int check_path(char **map)
{
	int	i;
	int y;

	i = -1;
	while(map[++i])
	{
		y = -1;
		while(map[i][++y])
		{
			
			if(map[i][y] == '0' || map[i][y] == 'C' || map[i][y] == 'E')
			return(0);
		}
	}
	return(1);	
}
char **cpymap(t_vars **v, char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	map = malloc(sizeof(char *) * (*v)->win_h);
	if(!map)
		return (NULL);
	while((*v)->map[i])
	{
		map[y] = (*v)->map[i];
		i++;
		y++;
	}
	return(map);
}
void	ft_freemap(char **tmp)
{
	int	i;

	i = 0;
	while(tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}
void	ft_floodfill(t_vars *v)
{
	int	x_p;
	int	y_p;
	char **tmp;

	tmp = cpymap(&v, tmp);
	x_p = 0;
	y_p = 0;
	find_player_position(tmp, &x_p,&y_p);
	flood_fill(tmp,y_p, x_p);
	if(!check_path(tmp))
	{
		printf("NO PATH");
		exit(1);
	}
	free(tmp);
}