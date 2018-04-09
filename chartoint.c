#include <stdio.h>
#include <string.h>

int main()
{
  char aaa;
  char temp[128]={0};
  aaa = 1;
  printf("%d\n", aaa);
  snprintf(temp,sizeof(temp),"%d", aaa);
  printf("2: %s\n", temp);
  return 0;
}
