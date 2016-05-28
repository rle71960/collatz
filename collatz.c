#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;

	int num = getUserInput(&num);

	while(num > 0) {
		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork Failed");
			return 1;
		}
		else if (pid == 0) {
			int col = num;
			while(col > 1) {
				printf(" %d, ", col);
				col = collatz(col);
			}
			printf(" %d\n", col);
			return 0;
		}
		else {
			wait(pid);
			num = getUserInput(&num);
		}

	}
}

int getUserInput(int *in) {
	printf("What is your number? ");
	int read = scanf("%d", &in);
	// read != 1 when char is entered
	if (read == 1)
	{
		printf("\n");
		return (int) in;
	}
	exit(0);
}

int collatz(int in) {
	int num = (int) in;
	if ( num % 2 == 0 ) {
		num = num / 2;
	}
	else {
		num = num * 3 + 1;
	}
	return (int) num;
}
