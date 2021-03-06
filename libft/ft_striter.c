/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymekraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:49:06 by ymekraou          #+#    #+#             */
/*   Updated: 2018/11/24 03:51:03 by ymekraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	if (s != 0 && f != 0)
	{
		i = 0;
		while (s[i] != '\0')
		{
			(*f)(s + i);
			i++;
		}
	}
}
