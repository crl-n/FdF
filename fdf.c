/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:21:23 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/08 19:28:02 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
//#include <stdio.h> //remove
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
	int		line_len;

	gnl_ret = get_next_line(fd, &line);
	if (gnl_ret < 0)
		die("Get next line error.");
	line_len = gnl_ret;
	while (1)
	{
		gnl_ret = get_next_line(fd, &line);
		if (gnl_ret == 0)
			break ;
		if (gnl_ret < 0 || gnl_ret != line_len)
			die("Get next line error.");
		node = ft_lstnew(NULL, 0);
		node->content = line;
		node->content_size = ft_strlen(line) + 1;
		ft_strdel(&line);
		ft_lstadd_back(&lines, node);
	}
	return (lines);
}

int	**parse_lines(t_list *lines)
{
	(void) lines;
	return (NULL);
}

int	**points_from_file(char *filename)
{
	int		fd;
	t_list	*lines;
	int		**points;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		die(USAGE);
	lines = read_lines(fd);
	points = parse_lines(lines);
	return (points);
}

int	key_event(int keycode, t_vars vars)
{
	//printf("%#x\n", keycode);
	if (keycode == 0x35)
	{
		mlx_destroy_window(vars.mlx, vars.win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_win	win;
	t_img	img;
	int		**points;

	(void) argv;
	(void) points;
	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	//points = points_from_file(argv[1]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fdf");
	win.width = WIDTH;
	win.height = HEIGHT;
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(vars.win, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	mlx_pixel_put(vars.mlx, vars.win, 50, 50, 0x00ff0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	vars.win = &win;
	mlx_key_hook(vars.win, key_event, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
