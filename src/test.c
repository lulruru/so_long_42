/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:11:09 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/28 17:46:41 by russelenc        ###   ########.fr       */
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
		render_image(&vars, x, y , "./texture/player.xpm"); 
	}
	if(c == 'C')
		render_image(&vars, x, y , "./texture/collectible.xpm");
	if(c == 'E')
		render_image(&vars, x, y , "./texture/exit.xpm");
	if(c == '0')
		render_image(&vars, x, y , "./texture/empty.xpm");

}

void gen_win(char **map,t_vars *vars)
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
			put_image(map[y_map][x_map],x, y,&vars );	
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