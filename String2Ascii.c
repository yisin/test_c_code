#include <stdio.h>
#include <string.h> 
#include <stdlib.h>


#define STR2ASCII(hex, str, len)  \
    do { \
         int i = 0;\
        for(i = 0; i < len; i++) {\
            hex[i] = str[i];\
        }\
    } while(0)

#define ASCII2STR(hex, str, len)  \
    do { \
         int i = 0;\
        for(i = 0; i < len; i++) {\
            str[i] = hex[i];\
        }\
    } while(0)    


int main() {

	//char str[25]="This is a test string";
	char str[25]="RT-AC68U";
	char revstr[25]={0};
	unsigned char hex[25] = {0};
	int i = 0, j = 0;
	STR2ASCII(hex, str, strlen(str));

	printf("str = %s\n", str);

	for(j=0;j<24;j++)
		printf("%02X ",hex[j]);

	printf("\n");

	ASCII2STR(hex, revstr, strlen(hex));
	printf("revstr = %s\n", str);


	char mac[]

	return 0;
}


#if 0

int test[25]={},i=0,j;
char a[25]="This is a test string.";
while(a[i]!='\0') {test[i]=a[i]; i++;}
for(j=0;j<i-1;j++) printf("%d ",test[j]);
return 0;


results:84 104 105 115 32 105 115 32 97 32 116 101 115 116 32 115 116 114 105 110 103 
#endif