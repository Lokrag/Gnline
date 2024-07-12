/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:29:38 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/31 20:29:43 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_from_file(int fd, char *buffer);
char	*check_newline(char **buffer, char *line);
size_t	strlen(const char *str);
char	*strdup(const char *s1);
char	*strchr(const char *str, int c);
char	*strjoin(char *s1, char const *s2);
int		main(int argc, char *argv[]);

#endif