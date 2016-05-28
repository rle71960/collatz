#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	int num = 1;

	while(num > 0) {
		num = getUserInput(&num);
		pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork Failed");
			return 1;
		}
		else if (pid == 0) {
			//do stuff
			int col = num;
			printf("The value of col is '%d'\n", col);
			while(col > 1) {
				printf(" %d, ", col);
				col = collatz(col);
			}
			printf(" %d\n", col);
		}
		else {
			wait(pid);
		}
	}
}

int getUserInput(int *in) {
	// doesn't handle char
	printf("What is your number? ");
	scanf("%d", &in);
	printf("\n");
	return (int) in;
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
