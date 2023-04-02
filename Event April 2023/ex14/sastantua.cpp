#include <iostream>
#include <string>

int	get_base(int size)
{
	int base = 7;
	int increment_by = 12;

	for (int increments = 1; increments < size; increments++)
	{
		base += increment_by;
		increment_by += (increments % 2 == 0 ? 4 : 2);
	}
	return (base);
}

void	fill(int size, int floor, int width, int step)
{
	int door_pos = (2 * ((floor - 1) / 2)) + 1;
	for (int pos = 0; pos < width; pos++)
	{
		if (pos == 0)
			std::cout << "/";
		else if (pos == width - 1)
			std::cout << "\\";
		else
		{
			if (floor == size && pos >= (width - door_pos) / 2 && pos < (width + door_pos) / 2 && floor - step + 2 <= door_pos)
				std::cout << ((door_pos >= 5 && step == floor - (door_pos / 2) + 1 && pos == ((width + door_pos) / 2) - 2) ? "$" : "|");
			else
				std::cout << "*";
		}
	}
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2 || std::stoi(av[1]) < 1)
		return (0);
	int	size = std::stoi(av[1]);
	int width = 1;
	for (int floor = 1; floor <= size; floor++)
	{
		for (int step = 0; step < floor + 2; step++)
		{
			width += 2;
			for (int i = 0; i < (get_base(size) - width) / 2; i++)
				std::cout << " ";
			fill(size, floor, width, step);
		}
		width += (2 * ((floor - 1) / 2)) + 4;
	}
	return (0);
}