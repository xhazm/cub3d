#include "./vector.h"

t_vector	ft_add_vector(t_vector vec1, t_vector vec2)
{
	t_vector ret_vec;

	ret_vec.x = vec1.x + vec2.x;
	ret_vec.y = vec1.y + vec2.y;
	ret_vec.z = vec1.z + vec2.z;
	return (ret_vec);
}

t_vector	ft_subtract_vector(t_point b, t_point a) //point b - point a = ab(vector)
{
	t_vector ret_vec;

	ret_vec.x = b.x - a.x;
	ret_vec.y = b.y - a.y;
	ret_vec.z = b.z - a.z;
	return (ret_vec);
}

t_vector	ft_mult_vector(t_vector vec, float	lambda) //skalarmult.
{
	t_vector ret_vec;

	ret_vec.x = vec.x * lambda;
	ret_vec.y = vec.y * lambda;
	ret_vec.z = vec.z * lambda;
	return (ret_vec);
}

void	ft_print_vector(t_vector vec)
{
	printf("vector:\tx:%f,\ty:%f,\tz:%f\n", vec.x, vec.y, vec.z);
}

int main(void)
{
	t_vector vec;
	t_vector vec2;
	t_vector vec3;

	vec.x = 1;
	vec.y = 2;
	vec.z = 3;
	vec2.x = 4;
	vec2.y = 2;
	vec2.z = 3;
	
	vec3 = ft_add_vector(vec, vec2);
	ft_print_vector(vec3);
}