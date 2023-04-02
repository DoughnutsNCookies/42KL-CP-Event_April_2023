#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (printf("Invalid number of arguments\n"));
	int	aces = 0;
	int sum = 0;
	for (int i = 0; av[1][i] != '\0'; i++)
	{
		if (av[1][i] == 'A')
			aces++;
		else if (av[1][i] == 'T' || av[1][i] == 'J' || av[1][i] == 'D' || av[1][i] == 'Q' || av[1][i] == 'K')
			sum += 10;
		else if (av[1][i] >= '2' || av[1][i] <= '9')
			sum += av[1][i] - '0';
		else
			return (printf("Invalid card: %c\n", av[1][i]));
	}
	while (aces--)
		sum += (sum + 11 <= 21) ? 11 : 1;
	printf(sum == 21 ? "Blackjack!\n" : "%d\n", sum);
}