#include <stdio.h>
#include <string.h>
void gen_lldpd_if(char *bind_ifnames);

int main() {

    char bind_ifnames[128] = {0};
    gen_lldpd_if(&bind_ifnames);
        printf("main: bind_ifnames = %s\n", bind_ifnames);
    return 0;
}

void gen_lldpd_if(char *bind_ifnames)
{

    char wan_ifname[16] = {0};
    char eth_ifnames[16] = {0};
    strcpy(wan_ifname, "vlan2");
    strcpy(eth_ifnames, "eth0");


    if(!memcmp(bind_ifnames, "", 128)){
        printf("1bind_ifnames is null\n");
    }

        if(wan_ifname != NULL) {
            if(strlen(bind_ifnames) == 0){
                bind_ifnames += sprintf(bind_ifnames, "%s", wan_ifname);
            }else{
                bind_ifnames += sprintf(bind_ifnames, ",%s", wan_ifname);
            }
        }
        if (wan_ifname != NULL && eth_ifnames != NULL && strcmp(wan_ifname, eth_ifnames)) {
            if(strlen(bind_ifnames) == 0){
                bind_ifnames += sprintf(bind_ifnames, "%s", eth_ifnames);
            }
            else{
                bind_ifnames += sprintf(bind_ifnames, ",%s", eth_ifnames);
            }
        }

    if(!memcmp(bind_ifnames, "", 128)){
        printf("2bind_ifnames is null\n");
    }

        printf("bind_ifnames = %s\n", bind_ifnames);
}