#include "parser.h"

unsigned int	ft_color_converter(char *cStr)
{
	int				i;
	char			**rgb;
	unsigned int	color;
	unsigned int	temp_color;

	rgb = ft_split(cStr, ',');
	color = 0;
	temp_color = 0;
	printf("rgb %s %s %s\n", rgb[0], rgb[1], rgb[2]);
	while (i < 3)
	{
		temp_color = ft_atoi(rgb[i]);
		printf("tempcolor%u\n", temp_color);
		if (temp_color > 255 || temp_color < 0)
			return (-1);
		color |= temp_color;
		if (i != 2)
			color = color << 8;
		i++;
	}
	ft_free2darr((void **)rgb);
	printf("BIT RGB %x\n", color);
	return (color);
}
