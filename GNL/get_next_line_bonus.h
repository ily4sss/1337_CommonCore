/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ily4s <ily4s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:30:12 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/11/15 16:04:36 by ily4s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFFER_SIZE 2

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
int		find_new_line(const char *buffer);
char	*get_next_line(int fd);
char	*cut_str(char *str, int i);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif