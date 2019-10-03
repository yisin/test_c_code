#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _wlc_status{
	int defif;
	int band; 		//	2:2.4G,5:5G
	int bandIndex;	// 	0,1,2...
	int priority; 	//	1,2,3...
	char wlcif[32];
	int use;
	char last_pap_bssid[18];
	char pap_bssid[18];
	int last_state;
	int state;
	int last_rssi;
	int rssi;
	int last_cost;
	int cost;
	int last_get_cost_result;
	int get_cost_result;
	int getpap_fail_count;
	int getstate_fail_count;
	int getrssi_fail_count;
	int getcost_fail_count;
}wlc_status,*pwlc_status;
wlc_status *wlcstat_list = NULL;

enum {
		NONE=2,
		WIFI_ONLY,
		ETHERNET_FIRST,
		AUTO_BY_COST,
		BAND2_FIRST,
		BAND5_FIRST,
		ETHERNET_ONLY,
		BAND2_ONLY,
		BAND5_ONLY,
};


int main()
{
char test[10]={0};
char test2[10]={0};
int y = 1;
int y2 = 1234;
int j = 0;
int printf_width = 38;
strcpy(test, "abcde");
strcpy(test2, "ffffffsfafasfaf");
//printf("%-*s", 20, test);
printf("aaasafdfsadf%daa%-*s = %d\n"
	   "bb%dbsdfsfbb%-*s = %d\n",
		y, printf_width, "",y,
		y2, printf_width, "",y2);

printf("aaasafdfsadf%daa%-*s ="
		"%d\n"
	 	"bb%dbsd[fsdfsdfssfbb%-*s ="
	 	"%d\n",
		y, printf_width - (int)strlen("aaasafdfsadfdaa"), "",y,
		y2, printf_width - (int)strlen("bbdbsdf[sdfsdfssfbb") - (int)strlen("1234"), "",y2);

printf("1:%d\n" ,printf_width - (int)strlen("aaasafdfsadfdaa"));
printf("2:%d\n" ,printf_width - (int)strlen("dbdsdfsdfsdfssfbb"));

printf("mode: %d\n", BAND5_ONLY);

wlcstat_list = (struct _wlc_status *) malloc(2 *sizeof(struct _wlc_status));

if (wlcstat_list == NULL) {
	printf("Can't alloc memory for wlcstat_list(%s)\n", __FUNCTION__);
	return 0;
}

	for (j = 0; j < 2; j++)
	{
		wlcstat_list[j].defif 					= 0;
		wlcstat_list[j].band 					= 0;
		wlcstat_list[j].bandIndex 				= j;
		wlcstat_list[j].priority 				= 100;
		snprintf(wlcstat_list[j].wlcif, sizeof(wlcstat_list[j].wlcif), "%s", "ethaa");
		wlcstat_list[j].use						= 1;
		memcpy(wlcstat_list[j].last_pap_bssid, "11:11:22:33:44:55", sizeof(wlcstat_list[j].last_pap_bssid));
		memcpy(wlcstat_list[j].pap_bssid, "00:11:22:33:44:55", sizeof(wlcstat_list[j].pap_bssid));
		wlcstat_list[j].last_state 				= -1;
		wlcstat_list[j].state 					= -1;
		wlcstat_list[j].last_rssi				= -1;
		wlcstat_list[j].rssi					= -1;
		wlcstat_list[j].last_cost				= -1;
		wlcstat_list[j].cost					= -1;
		wlcstat_list[j].last_get_cost_result	= -99;
		wlcstat_list[j].get_cost_result			= -99;
		wlcstat_list[j].getpap_fail_count 		= 0;
		wlcstat_list[j].getrssi_fail_count 		= 0;
		wlcstat_list[j].getstate_fail_count 	= 0;
		wlcstat_list[j].getcost_fail_count 		= 0;

		printf("strlen = %d printf-width = %d\n",(int)strlen("wlcstat_list[j].defif"),  printf_width - (int)strlen("wlcstat_list[j].defif"));
		printf("strlen = %d printf-width = %d\n", (int)strlen("wlcstat_list[j].last_get_cost_result"),  printf_width - (int)strlen("wlcstat_list[j].last_get_cost_result"));

printf("wlcstat_list[%d].defif%-*s					= %d\n"
		"wlcstat_list[%d].last_get_cost_result%-*s	= %s\n",
		j,17/2, "", wlcstat_list[j].defif,
		j, 2, "", "SUCCESS");

printf("#########################################################\n");
printf("wlcstat_list[%d].defif\t\t\t= %d\n"
		"wlcstat_list[%d].bandIndex\t\t= %d\n"
		"wlcstat_list[%d].band\t\t\t= %d\n"
		"wlcstat_list[%d].priority\t\t= %d\n"
		"wlcstat_list[%d].use\t\t\t= %d\n"
		"wlcstat_list[%d].last_state\t\t= %d\n"
		"wlcstat_list[%d].state\t\t\t= %d\n"
		"wlcstat_list[%d].last_rssi\t\t= %d\n"
		"wlcstat_list[%d].rssi\t\t\t= %d\n"
		"wlcstat_list[%d].last_cost\t\t= %d\n"
		"wlcstat_list[%d].cost\t\t\t= %d\n"
		"wlcstat_list[%d].getpap_fail_count\t= %d\n"
		"wlcstat_list[%d].getstate_fail_count\t= %d\n"
		"wlcstat_list[%d].getrssi_fail_count\t= %d\n"
		"wlcstat_list[%d].getcost_fail_count\t= %d\n"
		"wlcstat_list[%d].last_pap_bssid\t\t= %s\n"
		"wlcstat_list[%d].pap_bssid\t\t= %s\n"
		"wlcstat_list[%d].wlcif\t\t\t= %s\n"
		"wlcstat_list[%d].last_get_cost_result\t= %s\n"
		"wlcstat_list[%d].get_cost_result\t\t= %s\n",
		j, wlcstat_list[j].defif,
		j, wlcstat_list[j].bandIndex,
		j, wlcstat_list[j].band,
		j, wlcstat_list[j].priority,
		j, wlcstat_list[j].use,
		j, wlcstat_list[j].last_state,
		j, wlcstat_list[j].state,
		j, wlcstat_list[j].last_rssi,
		j, wlcstat_list[j].rssi,
		j, wlcstat_list[j].last_cost,
		j, wlcstat_list[j].cost,
		j, wlcstat_list[j].getpap_fail_count,
		j, wlcstat_list[j].getstate_fail_count,
		j, wlcstat_list[j].getrssi_fail_count,
		j, wlcstat_list[j].getcost_fail_count,
		j, wlcstat_list[j].last_pap_bssid,
		j, wlcstat_list[j].pap_bssid,
		j, wlcstat_list[j].wlcif,
		j, "SUCCESS",
		j, "Can't open file");
	}

free(wlcstat_list);
return 0;
}


#if 0
printf("\n\
		wlcstat_list[%d].defif%-*s					= %d\n\
		wlcstat_list[%d].bandIndex%-*s				= %d\n\
		wlcstat_list[%d].band%-*s					= %d\n\
		wlcstat_list[%d].priority%-*s				= %d\n\
		wlcstat_list[%d].wlcif%-*s					= %s\n\
		wlcstat_list[%d].use%-*s					= %d\n\
		wlcstat_list[%d].last_pap_bssid%-*s			= %s\n\
		wlcstat_list[%d].pap_bssid%-*s				= %s\n\
		wlcstat_list[%d].last_state%-*s				= %d\n\
		wlcstat_list[%d].state%-*s					= %d\n\
		wlcstat_list[%d].last_rssi%-*s				= %d\n\
		wlcstat_list[%d].rssi%-*s					= %d\n\
		wlcstat_list[%d].last_cost%-*s				= %d\n\
		wlcstat_list[%d].cost%-*s					= %d\n\
		wlcstat_list[%d].getpap_fail_count%-*s		= %d\n\
		wlcstat_list[%d].getstate_fail_count%-*s	= %d\n\
		wlcstat_list[%d].getrssi_fail_count%-*s		= %d\n\
		wlcstat_list[%d].getcost_fail_count%-*s		= %d\n\
		wlcstat_list[%d].last_get_cost_result%-*s	= %s\n\
		wlcstat_list[%d].get_cost_result%-*s		= %s\n",
		j, printf_width, wlcstat_list[j].defif,
		j, printf_width, wlcstat_list[j].bandIndex,
		j, printf_width, wlcstat_list[j].band,
		j, printf_width, wlcstat_list[j].priority,
		j, printf_width, wlcstat_list[j].wlcif,
		j, printf_width, wlcstat_list[j].use,
		j, printf_width, wlcstat_list[j].last_pap_bssid,
		j, printf_width, wlcstat_list[j].pap_bssid,
		j, printf_width, wlcstat_list[j].last_state,
		j, printf_width, wlcstat_list[j].state,
		j, printf_width, wlcstat_list[j].last_rssi,
		j, printf_width, wlcstat_list[j].rssi,
		j, printf_width, wlcstat_list[j].last_cost,
		j, printf_width, wlcstat_list[j].getpap_fail_count,
		j, printf_width, wlcstat_list[j].getstate_fail_count,
		j, printf_width, wlcstat_list[j].getrssi_fail_count,
		j, printf_width, wlcstat_list[j].getcost_fail_count,
		j, printf_width, wlcstat_list[j].cost,
		j, printf_width, amas_utils_str_error(wlcstat_list[j].last_get_cost_result),
		j, printf_width, amas_utils_str_error(wlcstat_list[j].get_cost_result));

#endif
