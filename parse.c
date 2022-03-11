/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:46:41 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/11 15:02:09 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //REMOVE
#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

static void	del(void *content, size_t content_size)
{
	(void) content_size;
	free(content);
}

static t_list	*read_lines(int fd)
{
	t_list	*lines;
	t_list	*node;
	char	*line;
	int		gnl_ret;

	while (1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == 0)
			break ;
		if (gnl_ret < 0)
			die("Get next line error.");
		node = ft_lstnew(NULL, 0);
		node->content = line;
		node->content_size = ft_strlen(line) + 1;
		ft_lstadd_back(&lines, node);
	}
	return (lines);
}

// Allocates and initialises
static int	**int_array_2d(int n_rows, int n_cols)
{
	int		**points;
	int		*cells;
	int		i;
	size_t	size;

	size = n_rows * sizeof (int *) + n_cols * sizeof (int);
	points = (int **) malloc(size);
	if (!points)
		die("Malloc fail.");
	ft_bzero(points, size);
	cells = (int *)(points + n_rows);
	i = 0;
	while (i < n_rows)
	{
		points[i] = cells + i * n_cols;
		i++;
	}
	return (points);
}

static int	**parse_lines(t_list *lines)
{
	int		**points;
	char	**split;
	int		n_cols;
	size_t	n_rows;
	int		i = 0;
	int		j = 0;
	int		k = 0;

	split = ft_strsplit(lines->content, ' ');
	n_rows = ft_lstsize(lines);
	n_cols = 0;
	while (split[n_cols])
		n_cols++;
	printf("number of columns %d\n", n_cols); //DEBUG
	printf("number of rows %zu\n", n_rows); //DEBUG
	points = int_array_2d(n_rows, n_cols);
	while (split[i])
		points[0][k++] = ft_atoi(split[i++]);
	free(split);
	lines = lines->next;
	j = 1;
	while (lines)
	{
		i = 0;
		k = 0;
		split = ft_strsplit(lines->content, ' ');
		while (split[i])
			points[j][k++] = ft_atoi(split[i++]);
		free(split);
		j++;
		lines = lines->next;
	}
	return (points);
}

//Debug, REMOVE
void	print_lines(t_list *lines)
{
	while (lines)
	{
		printf("%s\n", (char *)lines->content);
		lines = lines->next;
	}
}

// Does it need vars?
int	**points_from_file(char *filename, t_vars *vars)
{
	int		fd;
	t_list	*lines;
	int		**points;

	(void) vars;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die(USAGE);
	lines = read_lines(fd);
	print_lines(lines);
	points = parse_lines(lines);
	ft_lstdel(&lines, del);
	return (points);
}
