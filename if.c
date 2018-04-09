#include <stdio.h>
#include <string.h>

#define EXTEND_CAP_MASTER		0x0080

int main(){
   unsigned short test=0xd9;
   char test2;

   test2 = (test & EXTEND_CAP_MASTER)? 1:0;
   printf("test & EXTEND_CAP_MASTER = %d\n", test & EXTEND_CAP_MASTER);
   printf("test2 = %d\n", test2);
}
