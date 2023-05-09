/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: russelenc <russelenc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:40 by russelenc         #+#    #+#             */
/*   Updated: 2023/05/04 11:44:45 by russelenc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	nmbr_line(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

static void ft_trim(char *map)
{
	int	len;

	len = ft_strlen(map);
	if(map[len - 1] == '\n' && map)
		map[len - 1] = '\0';
}

char	**gen_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		return(NULL);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		return(NULL);
	return (ft_split(all_lines, '\n'));
}

/* 		int		fd;
	int		i;
	char	*tmp;

	map->map = malloc(sizeof(*map) * len + 1);
	if (!map->map)
		return (NULL);
	fd = open(fmap, O_RDONLY);
	if(fd < 0)
		printf("error");
	i = 0;
	while (i < len)
	{
		tmp = get_next_line(fd);
		map->map[i] = tmp;
		ft_trim(map->map[i]);
		i++;
	}
	close(fd);
	return (map->map); */