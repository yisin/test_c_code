#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void gen_lldpd_desc(char *bind_desc);

int main () {
	char bind_desc[64]={0};
	printf("==== bind_desc = %s\n", bind_desc);
	gen_lldpd_desc(&bind_desc[0]);
	printf("==== bind_desc = %s\n", bind_desc);
}

void gen_lldpd_desc(char *bind_desc)
{
	//0:eth1,wds0;1:eth2,wds1;2:eth3,wds2
	//0:eth1,wds0;1:eth2,wds1;2:eth3,wds2
	char sta_ifname[3][8]={"eth1", "eth2", "eth3"};
	int i = 0;

	for (i = 0; i<3;i++) {

			printf("sta_ifname[%d] = %s\n",i, &sta_ifname[i][0]);

		if (i == 0)
			bind_desc += sprintf(bind_desc,"%d:%s,wds%d", i,&sta_ifname[i][0], i);
		else
			bind_desc += sprintf(bind_desc,";%d:%s,wds%d", i,&sta_ifname[i][0], i);

		printf("bind_desc = %s\n", bind_desc);
	}

}