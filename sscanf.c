#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char maxassoc[]="128 (0x80)\0";
	int maxassoc_int = 0;
	char test[8]={0};
	sscanf(maxassoc, "%s", test);
	printf("maxassoc_int = %d\n", atoi(test));

	char macaddr[18]="E0:04:13:00:C1:00\0";
	char rmacaddr[13]={0};
	sscanf(macaddr, "", rmacaddr);
	printf("rmacaddr = %s\n", rmacaddr);

}
