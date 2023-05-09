/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:11:09 by russelenc         #+#    #+#             */
/*   Updated: 2023/05/04 11:44:36 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../so_long.h"
#include  <stdio.h>
#include <stdlib.h>

void	render_image(t_vars ***vars,int x, int y, char*img)
{
	int		img_w;
	int		img_h;

	(**vars)->img = mlx_xpm_file_to_image((**vars)->mlx, img, &img_w, &img_h);
	mlx_put_image_to_window((**vars)->mlx, (**vars)->win, (**vars)->img, x, y);
}

void put_image(char c, int x, int y, t_vars **vars)
{
	if(c == '1')
		render_image(&vars, x, y , "./texture/wall.xpm"); 
	if(c == 'P')
	{
		(*vars)->x_p = x;
		(*vars)->y_p = y;
		render_image(&vars, x, y , "./texture/player.xpm"); 
		printf(" x  = %d\n", (*vars)->x_p);
		printf(" y  = %d\n", (*vars)->y_p);
	}
	if(c == 'C')
		render_image(&vars, x, y , "./texture/collectible.xpm");
	if(c == 'E')
		render_image(&vars, x, y , "./texture/exit.xpm");
	if(c == '0')
		render_image(&vars, x, y , "./texture/empty.xpm");

}

void gen_win(t_vars *vars)
{
	int back;
	int x_map;
	int y_map;
	int x;
	int y;
	
	y = 0;
	y_map = 0;
	back = vars->win_w;
	while(0 < vars->win_h)
	{
		x = 0;
		x_map = 0;
		while(0 < vars->win_w)
		{
			put_image(vars->map[y_map][x_map],x, y,&vars );	
			x += 32;
			vars->win_w--;
			x_map++;
		}
		vars->win_w = back;
		y_map++;
		y += 32;
		vars->win_h--;
	} 
	
    // The following code goes here.
}

int	anime(t_vars *v)
{
	int	img_w;
	int	img_h;
	int x_c;
	int	y_c;
	int	i;
	int y;
	int len;

	x_c = 0;
	i = -1;
	y_c = 0;
	len = nmbr_line(v->map);
	
	v->img = mlx_xpm_file_to_image(v->mlx, "./texture/coffre.xpm", &img_w, &img_h);
	while(++i < len)
	{
		y = -1;
		while(v->map[i][++y])
		{
			if(v->map[i][y] == 'E')
			{
				x_c = y * 32;
				y_c = i * 32;
				if(v->collec <= 0)
				{
					mlx_put_image_to_window(v->mlx, v->win, v->img, x_c, y_c);
				}
				break ;
			}
		}
	}
	return(0);
}