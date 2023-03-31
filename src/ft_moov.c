/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:22:13 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/31 12:59:56 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collec(t_vars ***v)
{
	int		img_w;
	int		img_h;
	
	(**v)->collec--;
	(**v)->map[((**v)->y_p / 32)][((**v)->x_p / 32)] = '0';	
}

void	go_left(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image((*v)->mlx, "./texture/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32) - 1] == 'E')
	{
		if((*v)->collec <= 0)
			ft_exit(&v);
	}
	else if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32) - 1] != '1')
	{
			(*v)->x_p -= 32;
			print_move(&v);
	}
	if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32)] == 'C')
		collec(&v);
	(*v)->img = mlx_xpm_file_to_image((*v)->mlx, "./texture/left.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	go_right(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./texture/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32 + 1)] == 'E')
	{
		if((*v)->collec <= 0)
			ft_exit(&v);
	}
	else	if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32) + 1] != '1')
	{
			(*v)->x_p += 32;
			print_move(&v);
	}
	if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32)] == 'C')
		collec(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./texture/player.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	go_up(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./texture/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 32 - 1)][((*v)->x_p / 32)] == 'E')
	{
		if((*v)->collec <= 0)
			ft_exit(&v);
	}
	else if ((*v)->map[((*v)->y_p / 32) - 1][((*v)->x_p / 32)] != '1')
	{
			(*v)->y_p -= 32;
			print_move(&v);
	}
	if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32)] == 'C')
		collec(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./texture/player.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	go_down(t_vars **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./texture/empty.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if ((*v)->map[((*v)->y_p / 32 + 1)][((*v)->x_p / 32)] == 'E')
	{
		if((*v)->collec <= 0)
			ft_exit(&v);
	}
	else if ((*v)->map[((*v)->y_p / 32) + 1][((*v)->x_p / 32)] != '1')
	{
			(*v)->y_p += 32;
			print_move(&v);
	}
	if ((*v)->map[((*v)->y_p / 32)][((*v)->x_p / 32)] == 'C')
		collec(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./texture/player.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}