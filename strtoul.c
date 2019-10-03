#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALL_WL_MASK 0x700000

#define ETH_MAX_BASE      0x008000
#define WL_MAX_BASE       0x800000
#define ETH1_U          0x001000
#define ETH2_U          0x002000
#define ETH3_U          0x004000
#define ETH4_U          0x008000
#define WL2G_U          0x100000
#define WL5G1_U         0x200000
#define WL5G2_U         0x400000


int main ()
{
    char buffer [256];
    int ul;
    int amas_bhmode = 0x773300;
    int trigger_band = 0;

   // printf ("Enter an unsigned number: ");
    //fgets (buffer, 256, stdin);
    strcpy(buffer,"");
    ul = strtoul (buffer, NULL, 16);
    printf ("Value entered: %02X.\n", ul);

   char str_active[32]={0};
   snprintf(str_active, sizeof(str_active), "%X", (amas_bhmode & ALL_WL_MASK));

    printf ("trigger_band = %02X str_active =: %s.\n",trigger_band, str_active);


    trigger_band = ((amas_bhmode & ALL_WL_MASK) & ~WL5G1_U);

    printf ("trigger_band = %02X\n",trigger_band);


    printf("strlen(2 0 2 1 5 1 3 0 5 2 1 1) = %d, strlen(2 0 2 1 5 2 1 1) = %d\n", strlen("2 0 2 1 5 1 3 0 5 2 1 1"), strlen("2 0 2 1 5 2 1 1"));

    return 0;
}
