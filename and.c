#include <stdio.h>
#include <stdlib.h>

int main() {
	char mac[1]={0x74};
	printf("%02X\n", mac[0]);

	mac[0] = mac[0] | 0x02;
	printf("==== %02X\n", mac[0]);


}