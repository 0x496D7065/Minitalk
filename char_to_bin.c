/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:50:11 by lpetit            #+#    #+#             */
/*   Updated: 2024/02/09 10:33:45 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*char_to_bin(int c)
{
	char	*base;
	char	*str;
	int		i;

	base = "01";
	i = 7;
	str = ft_calloc(9, sizeof(char));
	str[i + 1] = '\0';
	while (c > 0)
	{
		str[i--] = base[c % 2];
		c /= 2;
	}
	while (i >= 0)
		str[i--] = '0';
	return (str);
}
