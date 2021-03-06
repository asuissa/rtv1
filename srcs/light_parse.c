/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:40:54 by asuissa           #+#    #+#             */
/*   Updated: 2019/04/18 14:16:29 by ymekraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		light_parse_basics(t_light *light, char *line)
{
	char	**tab;

	if (!(tab = parse_word(line)))
		return (0);
	if (ft_strcmp(tab[0], "\tposition.x") == 0)
		light->pos[0] = ft_atoi_double(tab[1]);
	else if (ft_strcmp(tab[0], "\tposition.y") == 0)
		light->pos[1] = ft_atoi_double(tab[1]);
	else if (ft_strcmp(tab[0], "\tposition.z") == 0)
		light->pos[2] = ft_atoi_double(tab[1]);
	else if (ft_strcmp(tab[0], "\tangle.x") == 0)
		light->light_angle[0] = (ft_atoi_double(tab[1]) * M_PI) / 180.0;
	else if (ft_strcmp(tab[0], "\tangle.y") == 0)
		light->light_angle[1] = (ft_atoi_double(tab[1]) * M_PI) / 180.0;
	else if (ft_strcmp(tab[0], "\tangle.z") == 0)
		light->light_angle[2] = (ft_atoi_double(tab[1]) * M_PI) / 180.0;
	else
	{
		free_split_tab(tab);
		return (0);
	}
	free_split_tab(tab);
	return (1);
}

int		light_parse_attributes(t_light *light, char *line)
{
	char	**tab;

	if (!(tab = parse_word(line)))
		return (0);
	if (ft_strcmp(tab[0], "\taperture") == 0)
		light->aperture = ft_atoi_double(tab[1]);
	else if (ft_strcmp(tab[0], "\tcolor") == 0)
		light->color = ft_atoi_hexa(tab[1]);
	else if (ft_strcmp(tab[0], "\tpower") == 0)
		light->power = ft_atoi_double(tab[1]);
	else
	{
		free_split_tab(tab);
		return (0);
	}
	free_split_tab(tab);
	return (1);
}

int		light_parse(t_light *light, char *line)
{
	if (light_parse_basics(light, line))
		return (1);
	if (light_parse_attributes(light, line))
		return (1);
	return (0);
}
