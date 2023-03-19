/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:36:03 by marai             #+#    #+#             */
/*   Updated: 2022/10/24 01:21:50 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strndupfree(char *s1, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strjoinfree(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *buf1, const void *buf2, size_t n);
char	*get_next_line(int fd);
char	*nullcheck(char fd, char *ans, char *save);
char	*returnvalue(char *ans, char *save);
char	*set_free(char	**str);

#endif