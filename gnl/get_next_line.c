/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:29:27 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/05/31 20:29:30 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin_mine(const char *s1, const char *s2)
{
	char	*str = NULL;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*read_from_file(int fd, char *buffer)
{
	int	ret;
	char	*getchars = NULL;

	getchars = (char *)malloc(BUFFER_SIZE + 1);
	ret = read(fd, getchars, BUFFER_SIZE);
	if (ret == -1)
	{
		free(getchars);
		return (NULL);
	}
	getchars[ret] = '\0';
	buffer = strjoin(buffer, getchars);
	free(getchars);
	return (buffer);
}

char	*check_newline(char **buffer, char *line)
{
	char	*temp;
	char	*track_buffer;
	int	flag;

	flag = 1 ;
	track_buffer = *buffer;
	while ((track_buffer = strchr(track_buffer, '\n')) && flag )
	{
		flag = 0;
		//temp = strdup(line);
		//free(line);
		line = strjoin_mine(line, *buffer);
		//free(temp);
		//free(line);
	}
	*buffer = ++track_buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line = NULL;
	static char	*buffer = NULL;

	if (buffer == NULL)
	{
		buffer = (char *)malloc(BUFFER_SIZE +1);
		if (buffer == NULL)
		{
			free(buffer);
			return (NULL);
		}
	}
	buffer = read_from_file(fd,  buffer);
	line = strdup("");
	line = check_newline(&buffer, line);
	return (line);
}
