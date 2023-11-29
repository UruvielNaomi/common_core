/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstacia <nstacia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:47:49 by nstacia           #+#    #+#             */
/*   Updated: 2023/11/29 14:04:47 by nstacia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>

char	*get_next_line(int fd);
char	*process_buffer(char **remaining);
char	*read_and_buffer(int fd, char *remaining);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *src);
char	*ft_strndup(const char *src, size_t n);
int		ft_strlen(const char *str);

#endif
