#include "stdlib.h"
#include "time.h"
#include "stdio.h"

int main(void)
{
	struct tm *ptr;
	time_t lt = time(NULL);
	ptr=gmtime(&lt);
	printf("%s\n", asctime(ptr));
	return 0;
}
