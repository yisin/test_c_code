#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if 0
unsigned char s2x(const char c)
{
    switch(c) {
    case '0'...'9':
        return (unsigned char)atoi(&c);
    case 'a'...'f':
        return 0xa + (c-'a');
    case 'A'...'F':
        return 0xa + (c-'A');
    default:
        goto error;
    }
error:
   return 0;
}
#endif
unsigned int s2x(char c)
{
    switch(c) {
    case '0'...'9':
        return atoi(&c);
    case 'a'...'f':
        return 0xa + (c-'a');
    case 'A'...'F':
        return 0xa + (c-'A');
    default:
        goto error;
    }
error:
   return 0;
}

int STR2HEX(unsigned char *hex, char *str, int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
        hex[i] = (s2x(str[i*3]) << 4) + s2x(str[i*3 + 1]);
    }

    return 0;
}


int STR2HEX2(unsigned char *hex, char *str, int len) {
    int i = 0;
    for(i = 0; i < len; i++) {
        hex[i] = (s2x(str[i*2]) << 4) + s2x(str[i*2 + 1]);
    }
    return 0;
}


#if 0
#define STR2HEX2(hex, str,len)  \
    do { \
         int i = 0;\
        for(i = 0; i < len; i++) {\
            hex[i] = (s2x(str[i*2]) << 4) + s2x(str[i*2 + 1]);\
        }\
    } while(0)
#endif

typedef struct _ob_status{
    unsigned char neighmac[6];
    int obstatus;       //1 (OB_OFF),  2 (OB_Available), 3 (OB_REQ), 4 (OB_LOCKED), 5 (OB_SUCCESS)
}ob_status,*ptr_obstatus;

/*convert a string,which length is 18, to a macaddress data type.*/
#define MAC_LEN_IN_BYTE 6
# if 0
#define STR2HEX(hex, str,len)  \
    do { \
         int i = 0;\
        for(i = 0; i < len; i++) {\
            hex[i] = (s2x(str[i*3]) << 4) + s2x(str[i*3 + 1]);\
        }\
    } while(0)
#endif
#define HEXVAL(hex, value, len)  \
    do { \
         int i = 0, j = 0;\
         j = len - 1;\
        for(i = 0; i < len; i++) {\
            value |= (hex[i]<<(8*j));\
            j--;\
        }\
    } while(0)



int test(unsigned char *temp2) {
    char macaddr2[18] = "11,22,33,44,55,66";
    STR2HEX(temp2, macaddr2, 6);
    printf("%s %02x:%02X:%02X:%02x:%02X:%02X\n", __FUNCTION__,temp2[0], temp2[1],temp2[2],temp2[3],temp2[4],temp2[5]);


}

char iscolon(unsigned char c)
{
    printf("c %02X\n", c);
    if ( c== 0x2C)
      return 1;

  return 0;
}

int cal_colon(char *s1)
{

  printf("s1 = %s\n", s1);

  int colon = 0;

    if(colon == 0 && iscolon(*s1)) {
        printf("config format is incorrect.\n");
        return 0;
    }

    while (*s1)
    {
       if (iscolon(*s1))
       {
           colon++;
       }
       s1++;
    }
    s1--;
    if(iscolon(*s1)) {
        printf("config format is incorrect.\n");
        return 0;
    }

    printf("parameter count = %d\n", colon+1);
   return colon + 1;
}


int main(int argc, char **argv)
{
    unsigned char hex[4] = {0};
    unsigned char s[4] = {0};
    memset(hex, 0x00, sizeof(hex));
   // char macaddr_str[18] = "00,00,00,11";
   // char macaddr_str[18] = "34,97,F6,5F,49,50";
    char macaddr_str[18]="64,EB,E0";
    unsigned char temp[7]={0};
    div_t chkval2;
    int chkval = 0;

    unsigned int len = 4, i = 0, output = 0, value=0;

    unsigned char *OriValue = NULL;
    unsigned char input_wifi_lastbyte[18] = {0};
    unsigned char wifi_lastbyte[18]={0};

    for (i=1; i<argc; i++)
    {

        memcpy(input_wifi_lastbyte, argv[i], sizeof(input_wifi_lastbyte));
        printf("Input wifi lastbyte = %s\n", input_wifi_lastbyte);
        printf("input_wifi_lastbyte  = %02X%02X%02X%02X%02X%02X%02X%02X\n", input_wifi_lastbyte[0], input_wifi_lastbyte[1], input_wifi_lastbyte[2], input_wifi_lastbyte[3], input_wifi_lastbyte[4], input_wifi_lastbyte[5],  input_wifi_lastbyte[6],  input_wifi_lastbyte[7]);

        chkval = cal_colon(input_wifi_lastbyte);
        printf("chkval = %d\n", chkval);
       // printf("len  = %d\n", strlen(input_wifi_lastbyte));



        STR2HEX(wifi_lastbyte , input_wifi_lastbyte, chkval);

        printf("wifi_lastbyte  = %02X%02X%02X%02X%02X%02X%02X%02X\n", wifi_lastbyte[0], wifi_lastbyte[1], wifi_lastbyte[2], wifi_lastbyte[3], wifi_lastbyte[4], wifi_lastbyte[5], wifi_lastbyte[5], wifi_lastbyte[6]);


    }

 // char wifi_lastbyte[4]={0};
    int wifi_lastbyte_int=0x64EBE0;
    char wifi_lastbyte_str[17]={0};
   unsigned char wifi_lastbyte_HEX[17]={0};
    snprintf(wifi_lastbyte_str,sizeof(wifi_lastbyte_str), "%02X", wifi_lastbyte_int);

    for (i = 0; i < strlen((char*)wifi_lastbyte_str);i++) {
          printf("wifi_lastbyte_str[%d] = %02X\n", i, wifi_lastbyte_str[i]);
    }



    printf("wifi_lastbyte_str = %s\n", wifi_lastbyte_str);

    STR2HEX2(wifi_lastbyte_HEX,wifi_lastbyte_str,strlen((char*)wifi_lastbyte_str));

    for (i = 0; i < strlen((char*)wifi_lastbyte_str);i++) {
          printf("wifi_lastbyte_HEX[%d] = %02X\n", i, wifi_lastbyte_HEX[i]);
    }


















    OriValue = malloc(4 * sizeof(char));
    memset(OriValue, 0x00, sizeof(OriValue));

    ob_status *Pobstatus = NULL;
    Pobstatus = (struct _ob_status *)malloc(2 *sizeof(struct _ob_status));
    memset(Pobstatus, 0x00, sizeof(2 *sizeof(struct _ob_status)));

    STR2HEX(OriValue,macaddr_str, 6);
     printf("OriValue[0]=%02X,OriValue[1]=%02X,OriValue[2]=%02X,OriValue[3]=%02X\n",
                                OriValue[0], OriValue[1],OriValue[2], OriValue[3]);
    //int result = 0;
    STR2HEX(hex,macaddr_str, len);
    printf("================0x%02x 0x%02x 0x%02x 0x%02x\n",hex[0],hex[1], hex[2],hex[3]);
   // result = strtoul(macaddr, NULL, 10);
    printf ("hex[0]<<24) = %02X\n", hex[0]<<24);
    printf ("hex[1]<<16) = %02X\n", hex[1]<<16);
    printf ("hex[2]<<8) = %02X\n", hex[2]<<8);

    int var = (hex[0]<<24)|(hex[1]<<16)|(hex[2]<<8)|hex[3];
    printf ("result = %d\n", var);

    HEXVAL(hex, value, len);
    HEXVAL(OriValue,  Pobstatus[0].obstatus, len);
    printf ("value = %d,  Pobstatus[0].obstatus=%d\n", value,  Pobstatus[0].obstatus);

    char macaddr2[18] = "D8,50,E6,45,0E,21";
    STR2HEX(Pobstatus[0].neighmac, macaddr2, 6);
    printf("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n",Pobstatus[0].neighmac[0],Pobstatus[0].neighmac[1], Pobstatus[0].neighmac[2],Pobstatus[0].neighmac[3], Pobstatus[0].neighmac[4], Pobstatus[0].neighmac[5]);

    test(temp);
    printf("%s %02x:%02X:%02X:%02x:%02X:%02X\n", __FUNCTION__,temp[0], temp[1],temp[2],temp[3],temp[4],temp[5]);


#if 0
    char test[256]="F3F02C31F48A1260018E89E7DF300CF6F3F02C31F48A1260018E89E7DF300CF6F9BB02FB23DD80DF9A55ED43F99170B3";
    unsigned char test2[256]={0};
    STR2HEX2(test2,test,strlen((char*)test));

    for (i = 0; i < strlen((char*)test);i++) {
          printf("test2[%d] = %X, strlen((char*)test)=%d\n", i, test2[i], strlen((char*)test));
    }
#endif



    free(OriValue);
    free(Pobstatus);

    return 0;
}

#if 0
unsigned char a2x(const char c)
{
    switch(c) {
    case '0'...'9':
        return (unsigned char)atoi(&c);
    case 'a'...'f':
        return 0xa + (c-'a');
    case 'A'...'F':
        return 0xa + (c-'A');
    default:
        goto error;
    }
error:
   return 0;
}

/*convert a string,which length is 18, to a macaddress data type.*/
#define MAC_LEN_IN_BYTE 6
#define COPY_STR2MAC(mac,str)  \
    do { \
         int i = 0;\
        for(i = 0; i < MAC_LEN_IN_BYTE; i++) {\
            mac[i] = (a2x(str[i*3]) << 4) + a2x(str[i*3 + 1]);\
        }\
    } while(0)

int main(int argc, char **argv)
{
    unsigned char macaddr[8] = {0};
    char macaddr_str[18] = "8e:b2:cf:89:00:4a";
    COPY_STR2MAC(macaddr,macaddr_str);
    printf("0x%02x 0x%02x\n",macaddr[0],macaddr[1]);

    return 0;
}
#endif


#if 0
int main(void)
{
    char achSrc[] = "00:FF:0A:0C:06:03";
    unsigned char mac[6] = {0};

    sscanf(achSrc, "%02x:%02x:%02x:%02x:%02x:%02x", &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5]);
    printf("Mac is %s,mac is %02x%02x%02x%02x%02x%02x\n",achSrc,mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);

    return 0;
}
#endif


