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

}
