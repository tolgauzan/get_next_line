/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:26:57 by tuzan             #+#    #+#             */
/*   Updated: 2024/11/27 22:26:57 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_free(char *reads, char *buff)
{
	if (reads)
		free(reads);
	if (buff)
		free(buff);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
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

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_append(char *reads, char *buff)
{
	char	*new_reads;
	size_t	r_len;
	size_t	b_len;

	r_len = ft_strlen(reads);
	b_len = ft_strlen(buff);
	new_reads = (char *)malloc((r_len + b_len + 1) * sizeof(char));
	if (!new_reads)
		return (free(reads), NULL);
	if (reads)
		ft_memcpy(new_reads, reads, r_len);
	ft_memcpy(new_reads + r_len, buff, b_len);
	new_reads[r_len + b_len] = '\0';
	free(reads);
	return (new_reads);
}
