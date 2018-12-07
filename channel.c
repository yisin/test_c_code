#include <stdio.h>
int main()
{
	char *t_code_noselect_2G[]={"EU", "RU", "EE", "UK", "DE", "TR", "CZ", "JP", "SG", "CN", "UA", "KR", "AU"};
	char *t_code_noselect_5G[]={"CA", "TW", "EU", "RU", "EE", "UK", "DE", "TR", "CZ", "JP", "KR"};
	char *t_code_noselect3_5G[]={"UA"};
	char *reg_2g[]={"2G_CH11", "2G_CH13", "2G_CH14"};
	char *reg_5g[]={"5G_BAND14", "5G_BAND123", "5G_BAND1", "5G_BAND24", "5G_BAND4", "5G_BAND124"};
	
	char set_reg_2g[16]="2G_CH13";
	//char set_reg_2g[16]="2G_CH11";
	//char set_reg_5g[16]="5G_BAND123";
	char set_reg_5g[16]="5G_BAND14";
	char t_code[4]="KR";
	
	printf("t_code length = %d\n", sizeof(t_code_noselect_2G)/sizeof(&t_code_noselect_2G[0][0]));
	printf("t_code[0][0]= %s, sizeof(t_code[0][0]) = %d strlen(t_code[0][0]) = %d\n", &t_code_noselect_2G[0][0], sizeof(&t_code_noselect_2G[0][0]),strlen(&t_code_noselect_2G[0][0]) );

	int i =0;
	printf("reg_2g[1][0] = %s  set_reg_2g = %s\n", &reg_2g[1][0], set_reg_2g);	
	
	//2G_CH13, 2G No Selection T-Code, Skip channel 12, 13
	if(!strcmp(&set_reg_2g, &reg_2g[1][0])) { 
		for(i=0; i < (sizeof(t_code_noselect_2G)/sizeof(&t_code_noselect_2G[0][0])); i++) {
			printf("t_code[%d] = %s\n", i, &t_code_noselect_2G[i][0]);
			if(!strncmp(&t_code,&t_code_noselect_2G[i][0],2))
					printf("skip channel 12, 13\n");
		}
	}
	
	//5G_BAND14, 5G No Selection T-Code, skip band1
	printf("reg_5g[0][0] = %s  set_reg_5g = %s\n", &reg_5g[0][0], set_reg_5g);	
	if(!strcmp(&set_reg_5g, &reg_5g[0][0])) {   
		for(i=0; i < (sizeof(t_code_noselect_5G)/sizeof(&t_code_noselect_5G[0][0])); i++) {
			printf("t_code[%d] = %s\n", i, &t_code_noselect_5G[i][0]);
			if(!strncmp(&t_code,&t_code_noselect_5G[i][0],2))
					printf("skip band 1\n");
		}
	}
	
	//5G_BAND123, 5G No Selection T-Code
	printf("reg_5g[1][0] = %s  set_reg_5g = %s\n", &reg_5g[1][0], set_reg_5g);	
	if(!strcmp(&set_reg_5g, &reg_5g[1][0])) { 
		//skip band3
		for(i=0; i < (sizeof(t_code_noselect3_5G)/sizeof(&t_code_noselect3_5G[0][0])); i++) {
			printf("t_code[%d] = %s\n", i, &t_code_noselect3_5G[i][0]);
			if(!strncmp(&t_code,&t_code_noselect3_5G[i][0],2))
					printf("skip band 3\n");
		}
		//skip band2,band3		
		for(i=0; i < (sizeof(t_code_noselect_5G)/sizeof(&t_code_noselect_5G[0][0])); i++) {
			printf("t_code[%d] = %s\n", i, &t_code_noselect_5G[i][0]);
			if(!strncmp(&t_code,&t_code_noselect_5G[i][0],2))
					printf("skip band 2,3\n");
		}
	}	
}