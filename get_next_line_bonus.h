/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:03:09 by akheired          #+#    #+#             */
/*   Updated: 2024/02/12 15:43:09 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_str(int fd, char *lft_str);
size_t	ft_strlen(char *s);
int		find_new_line(char *str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_first_line(char *left_str);
char	*ft_last_line(char *left_str);

#endif