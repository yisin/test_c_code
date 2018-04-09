#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ETH 		0x01  	//ethernet
#define WL_2G 		0x02  	//2G
#define WL_5G 		0x04	//5G
#define WL_5G_1 	0x08	//5G-1

int main ()
{
	int eth0 = 0x00;
	int eth1 = 0x01;
	int eth2 = 0x02;
	int eth3 = 0x04;
	int eth4 = 0x08;
	int mask = 0;
	printf("0:%d\n", (0x0001<<0));
	printf("1:%d\n", (0x0001<<1));
	printf("2:%d\n", (0x0001<<2));
	printf("3:%d\n", (0x0001<<3));

	printf("0:%d\n", mask |= (0x0001<<0));
	printf("1:%d\n", mask |= (0x0001<<1));
	printf("2:%d\n", mask |= (0x0001<<2));
	printf("3:%d\n", mask |= (0x0001<<3));


	int path = -1;
	path |= ETH;
	printf("ETH = %d\n", path);
	path |= WL_5G_1;
	printf("ETH + WL_2G = %d\n",path);

	int res = 0;
	res = path & ETH;
	printf("ETH  = %d\n", res);
	res = 0;
	res = path & WL_5G;
	printf("WL_5G  = %d\n", res);

	res = 0;
	res = path & WL_5G_1;
	printf("WL_5G_1  = %d\n", res);

}