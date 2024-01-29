/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:50:11 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/27 17:38:09 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//#include <stdlib.h>

/*static int	ft_count_digit(int value)
{
	int	digit_count;

	digit_count = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= 2;
		digit_count++;
	}
	return (digit_count);
}*/

char	*char_to_bin(int c)
{
	char	*base;
	char	*str;
	int		i;

	base = "01";
	i = 7;
	//count = ft_count_digit(c);
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

/*#include <stdio.h>
int main(void)
{
	char	*str;

	str = char_to_bin(70);
	printf("%s\n", str);
	free(str);
}*/
