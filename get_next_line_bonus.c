/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:27:06 by tuzan             #+#    #+#             */
/*   Updated: 2024/11/27 22:27:06 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_update(char *reads)
{
	char	*new_reads;
	size_t	i;
	size_t	j;

	i = 0;
	while (reads[i] != '\n' && reads[i] != '\0')
		i++;
	if (reads[i] == '\0')
		return (ft_free(reads, NULL));
	new_reads = (char *)malloc((ft_strlen(reads) - i) * sizeof(char));
	if (!new_reads)
		return (ft_free(reads, NULL));
	j = 0;
	while (reads[++i])
		new_reads[j++] = reads[i];
	new_reads[j] = '\0';
	ft_free(reads, NULL);
	return (new_reads);
}

static char	*ft_parse(char *reads)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (reads[0] == '\0')
		return (NULL);
	while (reads[i] != '\n' && reads[i] != '\0')
		i++;
	if (reads[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (reads[j] != '\n' && reads[j] != '\0')
	{
		line[j] = reads[j];
		j++;
	}
	if (reads[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *reads)
{
	char	*buff;
	ssize_t	b_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(reads, NULL));
	b_read = 1;
	while (b_read > 0 && !ft_strchr(reads, '\n'))
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
			return (ft_free(reads, buff));
		buff[b_read] = '\0';
		reads = ft_append(reads, buff);
		if (!reads)
			return (ft_free(reads, buff));
	}
	ft_free(NULL, buff);
	return (reads);
}

char	*get_next_line(int fd)
{
	static char	*reads[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	reads[fd] = ft_read(fd, reads[fd]);
	if (!reads[fd])
		return (NULL);
	line = ft_parse(reads[fd]);
	if (!line)
	{
		free(reads[fd]);
		reads[fd] = NULL;
		return (NULL);
	}
	reads[fd] = ft_update(reads[fd]);
	return (line);
}
