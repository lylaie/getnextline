#include "get_next_line.h"

static char			*ft_strjoin(const char *s1, const char *s2)
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

static char			*ft_strdup(const char *str)
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

static int			check_line(char **stock, char **line)
{
		char		*tmp;
		char		*str;
		int			index;

		index = 0;
		str = *stock;
		while (str[index] != '\n')
		{
				if (!str[index])
						return (0);
				index++;
		}
		tmp = &str[index];
		*tmp = '\0';
		*line = ft_strdup(*stock);
		*stock = ft_strdup(tmp + 1);
		return (1);
}

static int			read_file(int fd, char *str, char **stock, char **line)
{
		int			result;
		char		*tmp;

		result = 0;
		while ((result = read(fd, str, BUFFER_SIZE)) > 0)
		{
				str[result] = '\0';
				if (*stock)
				{
						tmp = *stock ;
						*stock = ft_strjoin(tmp, str);
						free(tmp);
						tmp = NULL;
				}
				else
						*stock = ft_strdup(str);
				if (check_line(stock, line))
						break;
		}
		return ((result > 0 ? 1 : result));
}

int					get_next_line(int fd, char **line)
{
		static char *stock[BUFFER_SIZE];
		char		*tmp;
		int			index;
		int			ret;

		if ((fd < 0 || fd >= OPEN_MAX) || BUFFER_SIZE <= 0 || !line || \
		(!(tmp = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1))) ||\
		(read(fd, stock[fd], 0) < 0))
				return (GNL_ERROR);
		if (stock[fd])
				if (check_line(&stock[fd], line))
						return (GNL_SUCCESS);
		index = 0;
		while (index < BUFFER_SIZE)
				tmp[index++] = '\0';
		ret = read_file(fd, tmp, &stock[fd], line);
		free(tmp);
		if (ret != 0 || stock[fd] == NULL || stock[fd][0] == '\0')
		{
				if (!ret && *line)
						*line = NULL;
				return (ret);
		}
		*line = stock[fd];
		stock[fd] = NULL;
		return (GNL_SUCCESS);
}
