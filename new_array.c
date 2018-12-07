#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	int band = 1;
	int *wlst = malloc((band+1) * sizeof(int));
	wlst[0] = 10;
	wlst[1] = 20;
	printf("wlist[0] = %d  wlst[1]=%d\n", wlst[0], wlst[1]);
	free(wlst);
}