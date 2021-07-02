
#include "header.h"

intt main()
{
	intt round_num = 1;
	intt input = 0;
	intt guess[4];
	intt result[4];
	intt win = 0;
	intt random = -1;

	while (random == -1)
	{
		random = get_result();
	}
	printf("Bulls and Cows Game\n");

	while (win != 1)
	{
		int_to_str(result, random);
		printf("Round %d >>>\n\t", round_num);

		round_num += 1;

		printf("Your Guess: ");

		if (scanf("%d", &input) != 1)
		{
			printf("\033[40;31m\tInvalid Guess\n\033[0m");
			input = 0;
			continue;
		}
		input = check_input(input);
		if (input == -1)
		{
			printf("\033[40;31m\tInvalid Guess\n\033[0m");
			input = 0;
			continue;
		}

		int_to_str(guess, input);

		printf("\tResponse: ");
		win = game(guess, result);
	}
	printf("\033[40;33mBingo! Congratulations.\n\033[0m");

	return 0;
}
