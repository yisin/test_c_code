#include <unistd.h>
#include <signal.h>
void handler()
{
    printf("hello\n");
}
#define TEST 1
main()
{
    int i;
    signal(SIGALRM, handler);
    alarm(5);
    for(i = 1; i < 7; i++)
    {
        printf("sleep %d ...\n", i);
        sleep(1);
    }
#ifdef TEST    
    if (i == 8)
    	printf("i = %d\n", i);
    else
#endif
	if (i == 7) 
		printf("ii = %d\n", i);    
}