/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:46:41 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/24 15:41:35 by carlnysten       ###   ########.fr       */
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

// Sets the dimension variables in the vars struct
static void	set_vars(int n_rows, char **split, t_vars *vars)
{
	int	n_cols;

	n_cols = 0;
	while (split[n_cols])
		n_cols++;
	vars->n_rows = n_rows;
	vars->n_cols = n_cols;
}

static void	get_z_values(t_point **arr, t_vars *vars, char **split, int i)
{
	int		j;
	double	x;
	double	y;
	double	z;

	j = 0;
	while (split[j])
	{
		x = j - vars->n_cols / 2;
		y = i - vars->n_rows / 2;
		z = ft_atoi(split[j]);
		if (z < vars->min_z)
			vars->min_z = z;
		if (z > vars->max_z)
			vars->max_z = z;
		arr[i * vars->n_cols + j] = point(x, y, z, vars);
		j++;
	}
	if (j != vars->n_cols)
		die("Invalid amoount of columns");
}

static t_point	**parse_lines(t_list *lines, t_vars *vars,
				t_point **arr, char **split)
{
	int		i;

	i = 0;
	while (lines)
	{
		split = ft_strsplit(lines->content, ' ');
		if (!split)
			die("Error: First line is empty.");
		if (i == 0)
		{
			set_vars(ft_lstsize(lines), split, vars);
			arr = point_array(vars->n_rows, vars->n_cols);
		}
		get_z_values(arr, vars, split, i);
		free(split);
		i++;
		lines = lines->next;
	}
	return (arr);
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
	arr = parse_lines(lines, vars, NULL, NULL);
	ft_lstdel(&lines, del);
	close(fd);
	return (arr);
}
