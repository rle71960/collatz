#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

long getUserInput(long in);
long collatz(long in);

int main()
{
	pid_t pid;

	long num = getUserInput(num);

	while(num > 0) {
		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork Failed");
			return 1;
		}
		else if (pid == 0) {
			long col = num;
			while(col > 1) {
				printf(" %ld, ", col);
				col = collatz(col);
			}
			printf(" %ld\n", col);
			return 0;
		}
		else {
			wait(pid);
			num = getUserInput(num);
		}

	}
}

long getUserInput(long in) {
	printf("What is your number? ");
	int read = scanf("%d", &in);
	// read != 1 when char is entered
	if (read == 1)
	{
		printf("\n");
		return (long) in;
	}
	exit(0);
}

long collatz(long in) {
	long num = in;
	if ( num % 2 == 0 ) {
		num = num / 2;
	}
	else {
		num = num * 3 + 1;
	}
	return num;
}
