/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_new_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:39:47 by akheired          #+#    #+#             */
/*   Updated: 2024/01/23 11:58:49 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	find_new_line(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	return (i);
}
int main(){
	char *str = "The last\nthing is goodj";
	printf("%d\n", find_new_line(str, 0));
}