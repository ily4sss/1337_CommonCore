/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilait-sa <ilait-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:30:12 by ilait-sa          #+#    #+#             */
/*   Updated: 2026/11/15 18:17:07 by ilait-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
int		find_new_line(const char *buffer);
int		clean_exit(char **stash, char *buffer);
char	*get_next_line(int fd);
char	*cut_str(char *str, int i);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif
