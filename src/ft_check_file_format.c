/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:48:55 by russelenc         #+#    #+#             */
/*   Updated: 2023/04/11 22:20:54 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int ft_formatcmp(char *src, char *cmp)
{
	int	i;

	i = 0;
	while(src[i])
	{
		if(src[i] != cmp[i])
			return(0);
		i++;
	}
	if(src[i] == '\0')
		return(1);
	return(0);
}
char *ft_extract(char *map)
{
	int	i;
	int y;
	char *ret;
	
	i = 0;
	y = 0;
	while(map[i] != '.')
		i++;
	ret = malloc(sizeof(char *) * i + 1);
	if (!ret)
		return (NULL);
	while(map[i])
	{
		ret[y] = map[i];
		y++;
		i++;
	}
	ret[y] = '\0';
	return(ret);
}

void directory_check(char *map)
{
	int fd;
	
	fd = open(map, O_DIRECTORY);
	if(fd > 0)
	{
		ft_putstr("Error :\nmap is a directory\n");
		exit(1);
	}
}

/* 
PROBLEME ICI DE LEAK SUREMENT 
*map++ et plus de pb mais warning;

*/

void check_format(char *map)
{
	int i;
	char *format;
	
	directory_check(map);
	while(map[++i])
	{
		if(map[i] == '.')
		{
			format = ft_extract(map);
			if(ft_strlen(format) < 4 || ft_strlen(format) > 4)
			{
				free(format);
				ft_putstr("Error\nfile is not valid\n");
				exit (1);
			}
			if (ft_formatcmp(format, ".ber"))
				return ;
		}
	}
	free(format);
	ft_putstr("Error\nfile is not valid\n");
	exit (1);
}