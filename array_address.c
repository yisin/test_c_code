#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int test (char *macaddr) {
	printf("%s:%s\n",__FUNCTION__, macaddr);
	memcpy(macaddr, "test1234", sizeof(macaddr));
	return 0;
}

int isNull (char *string, int len) {
  int i = 0;
  int ret = 1;

  for(i = 0; i < len; i++)  {
  	if(string[i] != 0) {
  		return 0;
  	}
  }
  return 1;
}


int main() {
	char macaddr[20]={0};

	test(macaddr);

	printf("%s: macaddr = %s\n", __FUNCTION__, macaddr);

	unsigned char newarray[5]={0x0, 0x1, 0x2, 0x3, 0x4};
	unsigned char newarray2[5]={0x0, 0x0, 0x0, 0x0, 0x0};
	unsigned char newarray3[20]="001122334455";

	printf("strlen(newarray) = %d\n", strlen(newarray));
	printf("isNull(newarray) = %d\n", isNull(newarray, 5));
	printf("isNull(newarray2) = %d\n", isNull(newarray2, 5));
	printf("strlen(newarray3) = %d\n", strlen(newarray3));
}