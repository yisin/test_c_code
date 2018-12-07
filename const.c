#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset */
#include <unistd.h> /* close */

int main ()
{
	int BandCount = 6;
	const int a = BandCount -1 ;
	int j = 1; 
	j = a;
	char ifnames[64]={0};
	strncpy(ifnames, "apcli0", 7);
	sprintf(ifnames, "%s apclii0", ifnames);
	
	int *RETRY_COUNT = malloc(BandCount * sizeof(int));
	
	memset(RETRY_COUNT, 0x00, BandCount * sizeof(int));

	printf("ifnames = %s\n", ifnames);
	printf("sizeof = %d ,  sizeof(RETRY_COUNT)=%d, a = %d, j = %d\n",BandCount * sizeof(int),BandCount * sizeof(int),   a, j);
	printf("RETRY_COUNT[0] =%d, RETRY_COUNT[1]=%d, RETRY_COUNT[2]=%d, RETRY_COUNT[3]=%d, RETRY_COUNT[4]=%d, RETRY_COUNT[5]=%d\n", RETRY_COUNT[0], RETRY_COUNT[1], RETRY_COUNT[2], RETRY_COUNT[3], RETRY_COUNT[4], RETRY_COUNT[5]);
	return 0;
}