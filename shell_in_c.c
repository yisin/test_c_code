#include <stdio.h>
#include <stdlib.h>

int main() 
{

	pid_t pid;
	pid=fork();
	if (pid == 0 ){
	 /* you are in the child process*/
	     execlp("ls", NULL);
	}else{
	/* you are still in the parent process */
	    printf("child pid=%d\n",pid);
	}
}