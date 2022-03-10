/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/10 10:33:33 by carlnysten       ###   ########.fr       */
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

int	**init_points(int n_rows, int n_cols)
{


}

int	**parse_lines(t_list *lines)
{
	int		**points;
	char	**split;
	int		n_cols;
	size_t	n_rows;
	int		i = 0;
	//int		j = 0;
	int		k = 0;

	split = ft_strsplit(lines->content, ' ');
	n_rows = ft_lstsize(lines);
	n_cols = 0;
	while (split[n_cols])
		n_cols++;
	printf("number of columns %d\n", n_cols);
	printf("number of rows %zu\n", n_rows);
	points = (int **) malloc(n_rows * sizeof (int *) + n_cols * sizeof (int));
	if (!points)
		die("Malloc failed");
	while (split[i])
		points[0][k++] = ft_atoi(split[i++]);
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

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die(USAGE);
	lines = read_lines(fd);
	print_lines(lines);
	points = parse_lines(lines);
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
