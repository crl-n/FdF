/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:46:41 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/13 22:39:03 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //REMOVE
#include <fcntl.h>
#include <unistd.h>
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

// Sets the dimension variables in the vars struct
static void	set_vars(int n_rows, int n_cols, t_vars *vars)
{
	int	n;

	vars->n_rows = n_rows;
	vars->n_cols = n_cols;
	if (n_rows > n_cols)
		n = n_rows;
	else
		n = n_cols;
	if (WIDTH > HEIGHT)
		vars->scale = WIDTH / n;
	else
		vars->scale = HEIGHT / n;
	vars->max = n;
}

static int	get_n_cols(char **split)
{
	int	n_cols;

	n_cols = 0;
	while (split[n_cols])
		n_cols++;
	return (n_cols);
}

static int	**parse_lines(t_list *lines, t_vars *vars, int **arr, char **split)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	while (lines)
	{
		i = 0;
		k = 0;
		split = ft_strsplit(lines->content, ' ');
		if (j == 0)
		{
			set_vars(ft_lstsize(lines), get_n_cols(split), vars);
			printf("number of columns %d\n", vars->n_cols); //DEBUG
			printf("number of rows %d\n", vars->n_rows); //DEBUG
			arr = int_array_2d(vars->n_rows, vars->n_cols);
		}
		while (split[i])
		{
			arr[j][k++] = ft_atoi(split[i++]);
			if (abs(arr[j][k - 1]) > vars->max)
				vars->max = abs(arr[j][k - 1]);
		}
		free(split);
		j++;
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

int	**arr_from_file(char *filename, t_vars *vars)
{
	int		fd;
	t_list	*lines;
	int		**arr;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die(USAGE);
	lines = read_lines(fd);
	print_lines(lines);
	arr = parse_lines(lines, vars, NULL, NULL);
	ft_lstdel(&lines, del);
	vars->origin = vars->max / 2;
	close(fd);
	return (arr);
}
