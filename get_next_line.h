/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:02:14 by akheired          #+#    #+#             */
/*   Updated: 2024/01/29 18:39:08 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFUR_SIZE
#  define BUFFUR_SIZE 9
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

#endif