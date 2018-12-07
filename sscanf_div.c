#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _dpsta_ifinfo {
  int band; //2:2.4G,5:5G
	int bandIndex;// 0,1,2...
  int priority; //1,2,3...
  int state;
  int rssi;
  int cost;
  int hop;
}dpsta_info;


#define RSSI_SELECT_ABOVE -75
#define RSSI_SELECT_BELOW -80
#define DEFAULT_PRIORITY "2 0 2 5 1 1"


int cmp( const void *a , const void *b )
{
struct _dpsta_ifinfo *c = (dpsta_info *)a;
struct _dpsta_ifinfo *d = (dpsta_info *)b;
if(c->priority != d->priority) return c->priority - d->priority;
return 0;
}


int main(){
#if 0  
  dpsta_ifinfo dpsta[3];

  sscanf("1:0:2-2:1:5", "%d:%d:%d-%d:%d:%d", &dpsta[0].priority, &dpsta[0].bandIndex, &dpsta[0].band, &dpsta[1].priority, &dpsta[1].bandIndex, &dpsta[1].band);
  printf("======= %d  %d  %d %d  %d  %d\n", dpsta[0].priority, dpsta[0].bandIndex, dpsta[0].band, dpsta[1].priority, dpsta[1].bandIndex, dpsta[1].band);


  char format[]="%d:%d:%d-%d:%d:%d";
  sscanf("1:0:2-2:1:5", format, &dpsta[0].priority, &dpsta[0].bandIndex, &dpsta[0].band, &dpsta[1].priority, &dpsta[1].bandIndex, &dpsta[1].band);
  printf("2======= %d  %d  %d %d  %d  %d\n", dpsta[0].priority, dpsta[0].bandIndex, dpsta[0].band, dpsta[1].priority, dpsta[1].bandIndex, dpsta[1].band);
#endif  
  div_t chkval, chkval2;
  char band1[]="1 0 2";
  char band2[]="1 0 2 2 1 5";
 // char band3[]="1:0:2-2:1:5-3:1:5";
  char band3[]="2 0 3 5 1 2 5 2 1";
 // char band3[]="";
  char df_band[]="2 0 3 5 1 2 5 2 1";
  char *data = band3;
  int offset = 0;
  int bandNum = 0;

  
  printf("%d %d %d\n", strlen(band1), strlen(band2), strlen(band3));
  
  if (strlen(band3) == 0) {
    printf("priority is null, set to default priority.\n");
    data = DEFAULT_PRIORITY;
  }
  chkval = div(strlen(data)+1, 2);
  
  printf("Quo = %d, rem = %d\n", chkval.quot, chkval.rem);
  
  chkval2 = div(chkval.quot, 3);
  printf("Quo = %d, rem = %d\n", chkval2.quot, chkval2.rem);
  
  if ((chkval.rem != 0 && chkval2.rem != 0) || chkval2.quot == 0) {
    printf("priority is incorrect, set to default priority.\n");
    data = DEFAULT_PRIORITY;
  } 
  else {
    printf("priority is OK.\n");
  }
  
  dpsta_info *dpsta = (struct _dpsta_ifinfo *) malloc(chkval2.quot *sizeof(struct _dpsta_ifinfo));
  dpsta_info *dpsta2 = (struct _dpsta_ifinfo *) malloc(0 *sizeof(struct _dpsta_ifinfo));
    int count = 0;
    while (sscanf(data, " %d%d%d%n", &dpsta[count].band, &dpsta[count].bandIndex, &dpsta[count].priority, &offset) == 3)
    {
 
      if (dpsta[count].bandIndex == 1) {
        dpsta[count].state = 2;
        dpsta[count].rssi = -28;
        dpsta[count].hop = 3;
      }
      else if (dpsta[count].bandIndex == 2) {
         dpsta[count].state = 2;
        dpsta[count].rssi = -70;
         dpsta[count].hop = 2;
      }
      else {
         dpsta[count].state = 2;
        dpsta[count].rssi = -90;
        dpsta[count].hop = 2;
      }
      
        data += offset;
        printf("read: %d %d %d\n", dpsta[count].band,dpsta[count].bandIndex, dpsta[count].priority);
        count++;
    }
    
  
    
    qsort(dpsta,count,sizeof(dpsta[0]),cmp);
    
     int i = 0, minpri=0, selband =-1, bandIndex=-1, max_rssi= 0, selentry = -1;
    for(i =0; i < chkval2.quot ; i++) {
   
      printf("minpri = %d  dpsta[%d].priority= %d\n  \
         dpsta[%d].band= %d\n \
         dpsta[%d].bandIndex=%d\n  \
         dpsta[%d].state=%d\n  \
         dpsta[%d].rssi=%d\n  \
         dpsta[%d].cost=%d\n",          
        minpri, 
        i, dpsta[i].priority, 
        i, dpsta[i].band, 
        i, dpsta[i].bandIndex, 
        i, dpsta[i].state, 
        i, dpsta[i].rssi,
        i, dpsta[i].cost);
    }  
    
    
    printf("count = %d\n", count);
    i = 0, minpri=0, selband =-1, bandIndex=-1, max_rssi= 0, selentry = -1;
    for(i =0; i < chkval2.quot ; i++) {
#if 0   
      printf("minpri = %d  dpsta[%d].priority= %d\n  \
         dpsta[%d].band= %d\n \
         dpsta[%d].bandIndex=%d\n  \
         dpsta[%d].state=%d\n  \
         dpsta[%d].rssi=%d\n  \
         dpsta[%d].cost=%d\n",          
        minpri, 
        i, dpsta[i].priority, 
        i, dpsta[i].band, 
        i, dpsta[i].bandIndex, 
        i, dpsta[i].state, 
        i, dpsta[i].rssi,
        i, dpsta[i].cost);
#endif      
        if (dpsta[i].state == 2) {
          if(dpsta[i].rssi > RSSI_SELECT_ABOVE && dpsta[i].rssi < 0) {
              selentry = i;               
              break;
          }else if(dpsta[i].rssi < RSSI_SELECT_ABOVE && dpsta[i].rssi > RSSI_SELECT_BELOW && max_rssi == 0 || max_rssi < dpsta[i].rssi) {
              selentry = i;
              max_rssi = dpsta[i].rssi;               
          }else if(dpsta[i].band == 2) {
              selentry = i;
              break;    
          }else{
            selentry = i;
          }
        }
  
    }  
  
     selband = dpsta[selentry].band;
     bandIndex = dpsta[selentry].bandIndex;   
     printf("select max_rssi= %d band %d (index: %d)to bridge.\n", max_rssi, selband, bandIndex);
    
    
    
   printf("strstr = %p\n", strstr("eth1", "")); 
  printf("dpsta = %p\n", &dpsta[0]); 
  printf("dpsta2 = %p\n", &dpsta2[0]); 

 #if 0     
    char line[] = "100 185 400 11 1000";
    char *data = line;
    int offset;
    int n;
    int sum = 0;

    while (sscanf(data, " %d%n", &n, &offset) == 1)
    {
        sum += n;
        data += offset;
        printf("read: %5d; sum = %5d; offset = %5d\n", n, sum, offset);
    }

    printf("sum = %d\n", sum);
#endif

#if 0    
    char line[] = "100 185 400 11 1000 2000";
    char *data = line;
    int offset = 0;
    int n = 0;
    int n2 = 0;
    int n3 = 0;
    int sum = 0;

    while (sscanf(data, " %d%d%d%n", &n, &n2, &n3, &offset) == 3)
    {
        sum += n;
        data += offset;
        printf("read: %5d %5d %5d; sum = %5d; offset = %5d\n", n,n2,n3, sum, offset);
    }
#endif
    return 0;
   

}
