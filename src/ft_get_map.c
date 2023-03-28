/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:40 by russelenc         #+#    #+#             */
/*   Updated: 2023/03/28 13:54:08 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nmbr_line(char *fmap)
{
	int		fd;
	int		i;
	char	*tmp;

	fd = open(fmap, O_RDONLY);
	i = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		tmp = get_next_line(fd);
		free(tmp);		
		i++;
	}
	close(fd);
	return (i);
}

static void ft_trim(char *map)
{
	int	len;

	len = ft_strlen(map);
	if(map[len - 1] == '\n' && map)
		map[len - 1] = '\0';
}

char	**gen_map(int len, t_vars *map, char *fmap)
{
	int		fd;
	int		i;
	char	*tmp;

	map->map = malloc(sizeof(*map) * len + 1);
	if (!map->map)
		return (NULL);
	fd = open(fmap, O_RDONLY);
	i = 0;
	while (i < len)
	{
		tmp = get_next_line(fd);
		map->map[i] = tmp;
		ft_trim(map->map[i]);
		i++;
	}
	close(fd);
	return (map->map);
}