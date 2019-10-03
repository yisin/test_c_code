#include <stdio.h>
#include <string.h>

#define CHCONF_BW_SHIFT	12
#define CHCONF_BW_5		(0<<CHCONF_BW_SHIFT)
#define CHCONF_BW_10	(1<<CHCONF_BW_SHIFT)
#define CHCONF_BW_20	(2<<CHCONF_BW_SHIFT)
#define CHCONF_BW_40	(3<<CHCONF_BW_SHIFT)
#define CHCONF_BW_80	(4<<CHCONF_BW_SHIFT)
#define CHCONF_BW_160	(5<<CHCONF_BW_SHIFT)

#define WL_CHAN_BAND_5G		(1 << 2)	/* 5GHz-band channel */
#define WL_CHAN_RADAR		(1 << 3)	/* radar sensitive  channel */
#define WL_CHAN_INACTIVE	(1 << 4)	/* temporarily inactive due to radar */
#define WL_CHAN_PASSIVE		(1 << 5)	/* channel is in passive mode */

#define	CHINFO_2G	0
#define	CHINFO_5G	(1<<0)
#define	CHINFO_UAVL	(1<<1)
#define	CHINFO_AVBL	(1<<2)
#define	CHINFO_BLK	(1<<3)

#define ETH1_U					0x0010
#define ETH2_U					0x0020
#define WL2G_U					0x1000
#define WL5G1_U					0x2000
#define WL5G2_U					0x4000

#define ETH1_ONLY				0x001100
#define ETH2_ONLY				0x002200
#define ETH1_FIRST				0x703100
#define ETH2_FIRST				0x703200
#define ETH_ONLY_ETH1_FIRST		0x003100
#define ETH_ONLY_ETH2_FIRST		0x003200
#define WL2G_ONLY				0x110000
#define WL5G1_ONLY				0x220000
#define WL5G2_ONLY				0x440000
#define WL2G_FIRST				0x713000
#define WL5G1_FIRST				0x720300
#define WL5G2_FIRST				0x743000
#define WL_ONLY_2G_FIRST		0x710000
#define WL_ONLY_5G1_FIRST		0x720000
#define WL_ONLY_5G2_FIRST		0x740000
#define AUTO_BY_COST			0x773300
#define OLD_ETH1_FIRST			0x000002
#define OLD_AUTO_BY_COST		0x000003

#define ALL_FIRST_MASK			0x703000
#define WL_ONLY_MASK			0x700000
#define ETH_ONLY_MASK			0x003000

#define MAX_ETH						4
#define MAX_WIFI					4
#define ETH1_P					0x000100 //(ETH1_P << 0)
#define ETH2_P					0x000200 //(ETH1_P << 1)
#define ETH3_P					0x000300 //(ETH1_P << 2)
#define ETH4_P					0x000400
#define WL2G_P					0x010000
#define WL5G1_P					0x020000
#define WL5G2_P					0x040000

#define CHCONF_BW_MASK  0x7000
#define CHCONF_BW_SHIFT 12

#define CHCONF_BW_20  (2<<CHCONF_BW_SHIFT)
#define CHCONF_BW_40  (3<<CHCONF_BW_SHIFT)
#define CHCONF_BW_80  (4<<CHCONF_BW_SHIFT)
#define CHCONF_BW_160 (5<<CHCONF_BW_SHIFT)
#define CHCONF_BW_IS20(chconf)  (((chconf) & CHCONF_BW_MASK) == CHCONF_BW_20)
#define CHCONF_BW_IS40(chconf)  (((chconf) & CHCONF_BW_MASK) == CHCONF_BW_40)
#define CHCONF_BW_IS80(chconf)  (((chconf) & CHCONF_BW_MASK) == CHCONF_BW_80)
#define CHCONF_BW_IS160(chconf) (((chconf) & CHCONF_BW_MASK) == CHCONF_BW_160)


# define getName(var, str) sprintf(str, "%s", #var)
#define _STRINGIFY(s) #s
#define STRINGIFY(s) _STRINGIFY(s)

typedef struct _amas_bhctl_mode {
  char mode_string[32];
  int  mode_mask;
}amas_bhctl_mode;


struct _amas_bhctl_mode defined_amasbhmode[] =
{
  {"ETH1_ONLY",             0x001100},
  {"ETH2_ONLY",             0x002200},
  {"ETH1_FIRST",            0x503100},
  {"ETH2_FIRST",            0x503200},
  {"ETH_ONLY_ETH1_FIRST",   0x003100},
  {"ETH_ONLY_ETH2_FIRST",   0x003200},
  {"WL2G_ONLY",             0x110000},
  {"WL5G1_ONLY",            0x220000},
  {"WL5G2_ONLY",            0x440000},
  {"WL2G_FIRST",            0x513000},
  {"WL5G1_FIRST",           0x720300},
  {"WL5G2_FIRST",           0x543000},
  {"WL_ONLY_2G_FIRST",      0x510000},
  {"WL_ONLY_5G1_FIRST",     0x720000},
  {"WL_ONLY_5G2_FIRST",     0x540000},
  {"AUTO_BY_COST",          0x573300},
  {"OLD_ETH1_FIRST",        0x000002},
  {"OLD_AUTO_BY_COST",      0x000003},
  {"",  0}
};

void main() {

printf("CHONF_BW_5 = %d\n", CHCONF_BW_5);
printf("CHCONF_BW_10 = %d\n", CHCONF_BW_10);
printf("CHCONF_BW_20 = %d\n", CHCONF_BW_20);
printf("CHCONF_BW_40 = %d\n", CHCONF_BW_40);
printf("CHCONF_BW_80 = %d\n", CHCONF_BW_80);
printf("CHCONF_BW_160 = %d\n", CHCONF_BW_160);
printf("WL_CHAN_RADAR = %d\n", WL_CHAN_RADAR);
printf("WL_CHAN_BAND_5G = %d\n", WL_CHAN_BAND_5G);
printf("WL_CHAN_INACTIVE = %d\n", WL_CHAN_INACTIVE);
printf("WL_CHAN_PASSIVE = %d\n", WL_CHAN_PASSIVE);
printf("CHINFO_2G = %d\n", CHINFO_2G);
printf("CHINFO_5G = %d\n", CHINFO_5G);
printf("CHINFO_UAVL = %d\n", CHINFO_UAVL);
printf("CHINFO_AVBL = %d\n", CHINFO_AVBL);
printf("CHINFO_BLK = %d\n", CHINFO_BLK);
char test[32]={0};
strncpy(test, "", sizeof(test));
char *productid = test;

printf(" 0xD8 & 0x02 = %02x\n", 0xD8 & 0x02);
printf(" 0xDA & 0x02 = %02x\n", 0xDA & 0x02);
if ( (0xD8 & 0x02) == 0x00) {
	printf(" 0xD8 & 0x02 = %02x\n", 0xD8 & 0x02);
}
if ( (0xDA & 0x02) == 0x02) {
	printf(" 0xDA & 0x02 = %02x\n", 0xDA & 0x02);
}
printf("%02x\n", 0xD8 | 0x02);
printf("%02x\n", 0xDA & ~0x02);

printf("====================================");
printf("ETH1_U  = %02X\n", ETH1_U << 0);
printf("ETH2_U  = %02X\n", ETH1_U << 1);
printf("ETH3_U  = %02X\n", ETH1_U << 2);
printf("ETH4_U  = %02X\n", ETH1_U << 3);


printf("ETH1_FIRST &&  ETH1_P = %02X\n", ETH1_FIRST & ETH1_P);
printf("ETH1_FIRST &&  ETH2_P = %02X\n", ETH1_FIRST & ETH2_P);
printf("WL_ONLY_2G_FIRST &&  ETH1_P = %02X\n", WL_ONLY_2G_FIRST & ETH1_P);


printf("ETH2_U  = %02X\n", ETH1_U << 1);
printf("ETH3_U  = %02X\n", ETH1_U << 2);
printf("ETH4_U  = %02X\n", ETH1_U << 3);

char str[32]={0};
getName(ETH1_P, str);
printf("%s\n", str);
printf("\n\nPrinting two defined constants: %s\n", str);

int isFirst = 0;
 isFirst = (AUTO_BY_COST & (WL2G_P << 0)) > 0 ? 1 : 0;
printf("isFirst = %d\n", isFirst);
printf("result = %02X\n", ETH1_FIRST & ALL_FIRST_MASK);


int costif = 0;
costif =  ETH1_P | costif ;
printf("cost = %02X\n", costif);
costif =  ETH2_P | costif ;

printf("cost = %02X\n", costif);


printf("0x01 & 0x05 = %02X\n", (0x01 & 0x05));




printf("CHCONF_BW_40 = %02X\n",CHCONF_BW_40);
printf("CHCONF_BW_80 = %02X\n",CHCONF_BW_80);
printf("CHCONF_BW_160 = %02X\n",CHCONF_BW_160);

printf("CHCONF_BW_IS20 = %02X\n",CHCONF_BW_IS20(49258));
printf("CHCONF_BW_IS40 = %02X\n",CHCONF_BW_IS40(49258));
printf("CHCONF_BW_IS80 = %02X\n",CHCONF_BW_IS80(49258));
printf("CHCONF_BW_IS160 = %02X\n",CHCONF_BW_IS160(49258));

printf("CHCONF_BW_IS20 = %02X\n",CHCONF_BW_IS20(22066));
printf("CHCONF_BW_IS40 = %02X\n",CHCONF_BW_IS40(22066));
printf("CHCONF_BW_IS80 = %02X\n",CHCONF_BW_IS80(22066));
printf("CHCONF_BW_IS160 = %02X\n",CHCONF_BW_IS160(22066));

}
