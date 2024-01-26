/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:50:11 by lpetit            #+#    #+#             */
/*   Updated: 2024/01/26 11:37:29 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
//#include <stdlib.h>

static int	ft_count_digit(int value)
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
}

char	*char_to_bin(int c)
{
	char	*base;
	char	*str;
	int		count;

	base = "01";
	count = ft_count_digit(c);
	str = (char *)malloc((count + 2) * sizeof(char));
	str[count + 1] = '\0';
	while (count >= 0)
	{
		str[count--] = base[c % 2];
		c /= 2;
	}
	str[0] = '0';
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
