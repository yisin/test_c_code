#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int loop = 0;

static void start_function(int signo)
{

	loop = 1;

    printf("\n## amas_bhctrl_start ##\n");
}

static void pause_function(int signo)
{

	loop = 0;

    printf("\n## amas_bhctrl_pause ##\n");
}


int main() {

	signal(SIGUSR1, start_function);
	signal(SIGUSR2, pause_function);

	printf("signal is ready\n");

start:
	while (loop == 0) {
		printf("signal is not ready\n");
		pause();
	}


	while (loop) {
		printf("do something\n");
		sleep(3);
	}

	if (loop == 0) {
		goto start;
	}

	return 0;
}
