/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:39:52 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/28 16:49:56 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_key_hook(int keycode, t_vars *vars)
{
	int	i;
	
	i = 0;
	if(keycode == 53)
	{
		while(vars->map[i])
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return(0);
}