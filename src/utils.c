/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:52:18 by russelenc         #+#    #+#             */
/*   Updated: 2023/04/11 22:20:01 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



char *ft_strdup(char *src)
{
	int	i;
	int len;
	char *dest;
	
	len = ft_strlen(src);
	i = -1;
	dest = malloc(sizeof(char) * len + 1);
	if(!dest)
		return(NULL);
	while(src[++i])
		dest[i] = src[i];
	dest[i]= '\0';
	return(dest);
}

char **cpymap(t_vars **v, char **map)
{
	int	i;

	i = 0;
	map = malloc(sizeof(char *) * (*v)->win_h);
	if(!map)
		return (NULL);
	while((*v)->map[i])
	{
		map[i] = ft_strdup((*v)->map[i]);
		i++;
	}
	return(map);
}

void ft_putstr(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
		write(1, &str[i], 1);
}