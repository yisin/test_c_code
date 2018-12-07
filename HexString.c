#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[256] = "";

#define Hex2String(hex, str, len)  \
    do { \
         int i = 0;\
         char temp[3] = {0};\
        for(i = 0; i < len; i++) {\
            memset(temp, 0x00, sizeof(temp));\
            sprintf(temp, "%02x", str[i]);\
            strncat(hex, temp, strlen(temp));\
        }\
    } while(0)

int hex2str_x(unsigned char *hex, char *str, int hex_len)
{
        int i = 0;
        char *d = NULL;
        unsigned char *s = NULL;
        const static char hexdig[] = "0123456789ABCDEF";
        if(hex == NULL||str == NULL)
                return 0;
        d = str;
        s = hex;

        for (i = 0; i < hex_len; i++,s++){
                *d++ = hexdig[(*s >> 4) & 0xf];
                *d++ = hexdig[*s & 0xf];
        }
        *d = 0;
        return 1;
} /* End of hex2str */

int main()
{
  int i;
  char str[128]="RT-AC68U";
  unsigned char *result = NULL;

  result = malloc(strlen(str)* 3 * sizeof(char));

  char temp[3]={0};
 // MD5(string, strlen(string), result);

  // output
  for(i = 0; i < 20; i++){
    memset(temp,0x00, sizeof(temp));
    sprintf(temp, "%02x", str[i]);
    strcat(s, temp);
  }
  printf("Final Hex String: %s\n",s);


  Hex2String(result, str, strlen(str));
  printf("Final Hex String result: %s\n",result);

  free(result);


  char array1[6]={0x1, 0x22, 0x33, 0x4, 0x5, 0x6};
  char array2[6]={0x0, 0x22, 0x33, 0x4, 0x5, 0x6};
  char array1_1[64]={0};
  char array2_1[64]={0};

  hex2str_x(array1, array1_1, 6);
  hex2str_x(array2, array2_1, 6);
  printf("array1_1 = %s, len = %d\n", array1_1, strlen(array1_1));
  printf("array2_1 = %s, len = %d\n", array2_1, strlen(array2_1));


  return EXIT_SUCCESS;
}