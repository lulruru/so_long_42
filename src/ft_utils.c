/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:11:45 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/31 12:52:51 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



int 	anime(t_vars *v)
{
	int	img_w;
	int	img_h;
	int x_c;
	int	y_c;
	int	i;
	int y;
	int len;

	x_c = 0;
	i = 0;
	y_c = 0;
	len = nmbr_line(v->map_file);
	
	v->img = mlx_xpm_file_to_image(v->mlx, "./texture/coffre.xpm", &img_w, &img_h);
	while(i < len)
	{
		y = 0;
		while(v->map[i][y])
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
			y++;
		}
		i++;
	}
	return(0);
}