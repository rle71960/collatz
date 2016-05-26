#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	int num;

	pid = fork();
	while(getUserInput(&num) > 0) {
		//pid = fork();

		if (pid < 0) {
			fprintf(stderr, "Fork Failed");
			return 1;
		}
		else if (pid == 0) {
			//do stuff
			while(num > 1) {
				printf(" %d, ", num);
				num = collatz(&num);
			}
			printf(" %d", num);
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

int collatz(int *in) {
	int num = (int) in;
	if ( num % 2 == 0 ) {
		num = num / 2;
	}
	else {
		num = num * 3 + 1;
	}
	return (int) num;
}
