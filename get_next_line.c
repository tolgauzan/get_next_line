/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:10:10 by tuzan             #+#    #+#             */
/*   Updated: 2024/11/24 16:10:10 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_has_nl(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_update(char *content)
{
	char	*new_content;
	int		i;
	int		j;

	i = 0;
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] == '\0')
		return (ft_free(content, NULL));
	new_content = (char *)malloc((ft_strlen(content) - i + 1));
	if (new_content == NULL)
		return (ft_free(content, NULL));
	j = 0;
	while (content[++i])
		new_content[j++] = content[i];
	new_content[j] = '\0';
	free(content);
	return (new_content);
}

static char	*ft_parseline(char *content)
{
	char	*line;
	int		i;

	i = 0;
	if (content[0] == '\0')
		return (NULL);
	while (content[i] != '\n' && content[i])
		i++;
	if (content[i] == '\n')
		line = (char *)malloc((i + 2) * sizeof(char));
	else
		line = (char *)malloc((i + 1) * sizeof (char));
	if (!line)
		return (NULL);
	i = -1;
	while (content[++i] != '\n' && content[i] != '\0')
		line[i] = content[i];
	if (content[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_readline(int fd, char *content)
{
	char	*buff;
	ssize_t	b_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (ft_free(content, NULL));
	b_read = 1;
	while (b_read > 0 && ft_has_nl(content) == 0)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
			return (ft_free(content, buff));
		buff[b_read] = '\0';
		content = ft_concat(content, buff);
		if (!content)
			return (ft_free(content, buff));
	}
	ft_free(NULL, buff);
	return (content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = ft_readline(fd, content);
	if (!content)
		return (NULL);
	line = ft_parseline(content);
	if (!line)
		return (free(content), content = NULL, NULL);
	content = ft_update(content);
	return (line);
}
