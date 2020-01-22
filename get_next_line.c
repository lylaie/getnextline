/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 11:31:47 by audumont          #+#    #+#             */
/*   Updated: 2020/01/22 19:39:44 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin(const char *s1, const char *s2)
{
	char		*dest;
	char		*tmp;

	if (!s1 || !s2 || !(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s1)\
	+ ft_strlen(s2) + 1))))
		return (NULL);
	dest = tmp;
	while (*s1 != '\0')
		*dest++ = *s1++;
	while (*s2 != '\0')
		*dest++ = *s2++;
	*dest = '\0';
	return (tmp);
}

static char		*ft_strdup(const char *str)
{
	char		*tmp;
	size_t		index;

	index = 0;
	while (str[index])
		index++;
	if (!(tmp = (char*)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = -1;
	while (str[++index])
		tmp[index] = str[index];
	tmp[index] = '\0';
	return (tmp);
}

static int		ft_check_line(char **stock, char **line)
{
	char		*tmp;
	int			index;
	char		*str;

	index = 0;
	str = *stock;
	while (str[index] != '\n')
	{
		if (!(str[index]))
			return (0);
		index++;
	}
	str[index] = '\0';
	tmp = ft_strdup(&str[index + 1]);
	*line = ft_strdup(*stock);
	free(*stock);
	*stock = tmp;
	return (1);
}

static int		ft_read_file(int fd, char *str, char **stock, char **line)
{
	int			result;
	char		*tmp;

	result = 0;
	while ((result = read(fd, str, BUFFER_SIZE)) > 0)
	{
		str[result] = '\0';
		if (*stock)
		{
			tmp = *stock;
			*stock = ft_strjoin(tmp, str);
			free(tmp);
			tmp = NULL;
		}
		else
			*stock = ft_strdup(str);
		if (ft_check_line(stock, line))
			break ;
	}
	return ((result > 0 ? 1 : result));
}

int				get_next_line(int fd, char **line)
{
	static char *stock[BUFFER_SIZE < 0 ? -BUFFER_SIZE + 1 : BUFFER_SIZE + 1];
	char		*tmp;
	int			index;
	int			ret;

	if ((fd < 0 || fd >= OPEN_MAX) || BUFFER_SIZE <= 0 || !line || (!(tmp = \
	malloc(sizeof(char) * BUFFER_SIZE + 1))) || (read(fd, stock[fd], 0) < 0))
		return (GNL_ERROR);
	if (stock[fd])
		if (ft_check_line(&stock[fd], line))
			return (ft_free(tmp));
	index = 0;
	while (index < BUFFER_SIZE)
		tmp[index++] = '\0';
	ret = ft_read_file(fd, tmp, &stock[fd], line);
	free(tmp);
	if (ret != 0 || stock[fd] == NULL || stock[fd][0] == '\0')
	{
		if (!ret)
			*line = ft_strdup("");
		return (ret);
	}
	*line = stock[fd];
	stock[fd] = NULL;
	return (ret);
}
