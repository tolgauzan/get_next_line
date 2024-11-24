/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:10:05 by tuzan             #+#    #+#             */
/*   Updated: 2024/11/24 16:10:05 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_free(char *content, char *buff)
{
	if (content)
		free(content);
	if (buff)
		free(buff);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len++])
		;
	return (len - 1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

char	*ft_concat(char *content, char *buff)
{
	char	*new_content;
	size_t	cont_len;
	size_t	buff_len;

	if (!content)
		cont_len = 0;
	else
		cont_len = ft_strlen(content);
	buff_len = ft_strlen(buff);
	new_content = (char *)malloc((cont_len + buff_len + 1) * sizeof(char));
	if (!new_content)
		return (free(content), NULL);
	if (content)
		ft_memcpy(new_content, content, cont_len);
	ft_memcpy(new_content + cont_len, buff, buff_len);
	new_content[cont_len + buff_len] = '\0';
	free(content);
	return (new_content);
}
