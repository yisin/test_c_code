#include <stdio.h>
#include <string.h> 

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

/*convert a string,which length is 18, to a macaddress data type.*/
#define MAC_LEN_IN_BYTE 6
#define STR2HEX(mac,str,len)  \
    do { \
         int i = 0;\
        for(i = 0; i < len; i++) {\
            mac[i] = (s2x(str[i*3]) << 4) + s2x(str[i*3 + 1]);\
        }\
    } while(0)
  

int main(int argc, char **argv)
{
    unsigned char macaddr[4] = {0};
    unsigned char s[4] = {0};
    memset(macaddr, 0x00, sizeof(macaddr));
    char macaddr_str[18] = "00,00,00,11";
    int len = 4, i = 0, output = 0;
    //int result = 0;
    STR2HEX(macaddr,macaddr_str, len);
    printf("0x%02x 0x%02x 0x%02x 0x%02x\n",macaddr[0],macaddr[1], macaddr[2],macaddr[3]);
   // result = strtoul(macaddr, NULL, 10);

    int var = (macaddr[0]<<24)|(macaddr[1]<<16)|(macaddr[2]<<8)|macaddr[3];
    printf ("result = %d\n", var); 
   

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


