/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:46:41 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/14 10:45:56 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //REMOVE
#include <fcntl.h>
#include <unistd.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

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
/*
static int	**int_array_2d(int n_rows, int n_cols)
{
	int		**arr;
	int		*cells;
	int		i;
	size_t	size;

	size = n_rows * sizeof (int *) + n_cols * sizeof (int);
	arr = (int **) malloc(size);
	if (!arr)
		die("Malloc fail.");
	ft_bzero(arr, size);
	cells = (int *)(arr + n_rows);
	i = 0;
	while (i < n_rows)
	{
		arr[i] = cells + i * n_cols;
		i++;
	}
	return (arr);
}
*/

static t_point	**point_array(int n_rows, int n_cols)
{
	t_point	**arr;
	size_t	size;

	size = n_rows * n_cols * sizeof (t_point **);
	arr = (t_point **) malloc(size);
	if (!arr)
		die("Malloc fail.");
	ft_bzero(arr, size);
	return (arr);
}

// Sets the dimension variables in the vars struct
static void	set_vars(int n_rows, int n_cols, t_vars *vars)
{
	vars->n_rows = n_rows;
	vars->n_cols = n_cols;
	/*
	if (n_rows > n_cols)
		n = n_rows;
	else
		n = n_cols;
	if (WIDTH > HEIGHT)
		vars->scale = WIDTH / n;
	else
		vars->scale = HEIGHT / n;
	vars->max = n;
	vars->origin = n / 2;
	*/
}

static int	get_n_cols(char **split)
{
	int	n_cols;

	n_cols = 0;
	while (split[n_cols])
		n_cols++;
	return (n_cols);
}

static t_point	**parse_lines(t_list *lines, t_vars *vars,
				t_point **arr, char **split)
{
	int		i;
	int		j;

	i = 0;
	while (lines)
	{
		j = 0;
		split = ft_strsplit(lines->content, ' ');
		if (i == 0)
		{
			set_vars(ft_lstsize(lines), get_n_cols(split), vars);
			printf("number of columns %d\n", vars->n_cols); //DEBUG
			printf("number of rows %d\n", vars->n_rows); //DEBUG
			arr = point_array(vars->n_rows, vars->n_cols);
		}
		while (split[j])
		{
			arr[i * vars->n_cols + j] = point(i, j, ft_atoi(split[j]), vars);
			j++;
		}
		free(split);
		i++;
		lines = lines->next;
	}
	return (arr);
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

t_point	**arr_from_file(char *filename, t_vars *vars)
{
	int		fd;
	t_list	*lines;
	t_point	**arr;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die(USAGE);
	lines = read_lines(fd);
	print_lines(lines);
	arr = parse_lines(lines, vars, NULL, NULL);
	ft_lstdel(&lines, del);
	close(fd);
	return (arr);
}
