/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/11 14:39:54 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h> //remove
#include <fcntl.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

void	die(char *message)
{
	ft_putstr(message);
	exit(0);
}

t_list	*read_lines(int fd)
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

int	**parse_lines(t_list *lines)
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
	printf("number of columns %d\n", n_cols);
	printf("number of rows %zu\n", n_rows);
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

//Debug
void	print_lines(t_list *lines)
{
	while (lines)
	{
		printf("%s\n", (char *)lines->content);
		lines = lines->next;
	}
}

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
	//free lines
	return (points);
}

int	key_event(int keycode, t_vars vars) // Should t_vars be t_vars *?
{
	//printf("%#x\n", keycode);
	if (keycode == 0x35)
	{
		mlx_destroy_window(vars.mlx, vars.win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv) {
	t_vars	vars;
	t_win	win;
	int		**points;

	(void) points;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	points = points_from_file(argv[1], &vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fdf");
	win.width = WIDTH;
	win.height = HEIGHT;
	vars.win = &win;
	mlx_key_hook(vars.win, key_event, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
