#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "main.h"
#include "parse_scene/ps_parse_textures_utils.h"
#include "parse_scene/ps_utils.h"
#include "utils/u_.h"

static void	parse_texture_data(t_map *map, char *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
			map->map[x][y++] = parse_xyz(&data, MIN_COLOR, MAX_COLOR);
		++x;
	}
}

static void	parse_ppm_file(t_map *map, char *data)
{
	int	color_scale;

	if (!str_is_equal(data, "P3", 2))
		error_message_and_exit("PPM: Please provide P3 file");
	data += 3;
	map->width = parse_int(&data, MIN_PPM_SIZE, MAX_PPM_SIZE);
	map->height = parse_int(&data, MIN_PPM_SIZE, MAX_PPM_SIZE);
	map->map = allocate_map(map->width, map->height);
	color_scale = parse_int(&data, MIN_COLOR, MAX_COLOR);
	if (color_scale != MAX_COLOR)
		error_message_and_exit("PPM: Max color scale should be 255");
	parse_texture_data(map, data);
}

static bool	parse_texture_map(t_map *map, char **line)
{
	int		ppm_file;
	int		file_length;
	char	*path;
	char	*map_data;

	if (!(**line) || **line == '#')
		return (false);
	path = get_path(*line);
	ft_putstr("loading texture: ");
	ft_putstr(path);
	ft_putstr("\n");
	file_length = get_length_of_file(path);
	ppm_file = open(path, O_RDONLY);
	free(path);
	map_data = (char *)ft_calloc(sizeof(char), file_length);
	if (read(ppm_file, map_data, file_length) != -1)
		parse_ppm_file(map, map_data);
	while (**line && !ft_is_space(**line))
		*line += 1;
	while (**line && ft_is_space(**line))
		*line += 1;
	free(map_data);
	return (true);
}

void	parse_textures(t_object *object, char **line)
{
	object->checkerboard = false;
	object->texture = false;
	object->bump = false;
	if (str_is_equal(*line, "checkerboard", 12))
	{
		object->checkerboard = true;
		while (**line && !ft_is_space(**line))
			*line += 1;
		while (**line && ft_is_space(**line))
			*line += 1;
	}
	else if (parse_texture_map(&object->texture_map, line))
		object->texture = true;
	if (parse_texture_map(&object->bump_map, line))
		object->bump = true;
}
