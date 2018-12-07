#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include  <signal.h>
 #include <sys/time.h>

typedef struct _wl_br_status{
	int band; 		//	2:2.4G,5:5G
	int bandIndex;	// 	0,1,2...
	int priority; 	//	1,2,3...
	char wlcif[32];
	int rssi;
	int state;
	int hop;
}wl_br_status,*pwl_br_status;

typedef struct _eth_br_status{
	int ethIndex;	// 	0,1,2...
	int priority; 	//	1,2,3...
	char ethif[32];
	int state;
	int hop;
}eth_br_status,*peth_br_status;

void *update_wlc_status (void *list);
void *update_eth_status(void *list);
void select_bh_path(int sig);
sem_t wifi_sem;
sem_t eth_sem;

int value = 0;
int loop = 1;
int wait_time = 0;
	
pthread_mutex_t wifi_mutex;
pthread_mutex_t eth_mutex;
pthread_cond_t wifi_cond;
pthread_cond_t eth_cond;
wl_br_status *wlbrs_list = NULL;
eth_br_status *ethbrs_list	= NULL;

int main () {
	

	int res = 0;
	pthread_t wifi_thread, eth_thread;
	wait_time = 2;

	
	wlbrs_list = (struct _wl_br_status *) malloc(2 *sizeof(struct _wl_br_status));
	ethbrs_list = (struct _eth_br_status *) malloc(2 *sizeof(struct _eth_br_status));
	
    
	res = pthread_mutex_init(&wifi_mutex, NULL);
	if (res != 0) {
		printf("[update wireless info] semaphore initialization failed\n");
		goto exit;
	}
	
	res = pthread_cond_init(&wifi_cond, NULL);
	if (res != 0) {
		printf("[update wireless info] wifi_cond initialization failed\n");
		goto exit;
	}
	
	res = pthread_mutex_init(&eth_mutex, NULL);
	if (res != 0) {
		printf("[update ethernet info] semaphore initialization failed\n");
		goto exit;
	}	
	
	res = pthread_cond_init(&eth_cond, NULL);
	if (res != 0) {
		printf("[update wireless info] wifi_cond initialization failed\n");
		goto exit;
	}

	res = pthread_create (&wifi_thread, NULL, update_wlc_status, (void*)wlbrs_list);
	if (res != 0) {
		printf("wifi_thread creation failed");
		goto exit;
	}
	
	res = pthread_create (&eth_thread, NULL, update_eth_status, (void*)ethbrs_list);
	if (res != 0) {
		printf("eth_thread creation failed");
		goto exit;
	}
	
	signal(SIGALRM, select_bh_path);  
	alarm(wait_time);
	
	while(loop)
    {
    	;
    }
  
exit:	
	free(wlbrs_list);
	free(ethbrs_list);	
	exit(EXIT_SUCCESS);
}

//void select_bh_path(wl_br_status *wlbrs_list)
void select_bh_path(int sig)
{

		int j = 0;	
		alarm(wait_time);
		pthread_mutex_lock(&wifi_mutex);
		wlbrs_list[j].band = 0;
		
		wlbrs_list[j].bandIndex = j;
		wlbrs_list[j].priority = 100+j;
		memset(wlbrs_list[j].wlcif, 0x00, sizeof(wlbrs_list[j].wlcif));			
		memcpy(wlbrs_list[j].wlcif, "ra0", sizeof(wlbrs_list[j].wlcif));		
		wlbrs_list[j].state = 0;
		wlbrs_list[j].rssi	= -100;	
		wlbrs_list[j].hop	= 1;	
						
		printf("%s:%d wlbrs_list[j].priority  = %d \n",__FUNCTION__, __LINE__, wlbrs_list[j].priority);	
		pthread_mutex_unlock(&wifi_mutex);
			
}

void *update_wlc_status (void *list) {
	
	pthread_detach(pthread_self());
	int j = 0;
	struct timeval now;
	struct timespec outtime;
	
	wl_br_status *wlbrs_list = (struct _wl_br_status *) list;
	
	while(loop) {
		
		pthread_mutex_lock(&wifi_mutex);
		
		gettimeofday(&now, NULL);
		outtime.tv_sec = now.tv_sec + 2;
		outtime.tv_nsec = 0;
		pthread_cond_timedwait(&wifi_cond, &wifi_mutex, &outtime); 
		
		wlbrs_list[j].band = 0;
		wlbrs_list[j].bandIndex = j;
		wlbrs_list[j].priority = 100+j;
		memset(wlbrs_list[j].wlcif, 0x00, sizeof(wlbrs_list[j].wlcif));			
		strncpy(wlbrs_list[j].wlcif, "ra0", 3);		
		wlbrs_list[j].state = 0;
		wlbrs_list[j].rssi	= -100;	
		wlbrs_list[j].hop	= 1;	
						
		printf("%s:%d wlbrs_list[j].priority  = %d \n",__FUNCTION__, __LINE__, wlbrs_list[j].priority);
		pthread_mutex_unlock(&wifi_mutex);
	}
	pthread_exit(NULL);
}


void *update_eth_status(void *list)
{	
	pthread_detach(pthread_self());
	int j = 0;
	struct timeval now;
	struct timespec outtime;
	
	eth_br_status *ethbrs_list = (struct _eth_br_status *) list;

	while(loop) {
		pthread_mutex_lock(&eth_mutex);
		
		gettimeofday(&now, NULL);
		outtime.tv_sec = now.tv_sec + 2;
		outtime.tv_nsec = 0;
		pthread_cond_timedwait(&eth_cond, &wifi_mutex, &outtime); 
		
		
		ethbrs_list[j].ethIndex = j;
		ethbrs_list[j].priority = 100;
		memset(ethbrs_list[j].ethif, 0x00, sizeof(ethbrs_list[j].ethif));			
		memcpy(ethbrs_list[j].ethif, "eth0", sizeof(ethbrs_list[j].ethif));		
		ethbrs_list[j].state = 0 ;
		ethbrs_list[j].hop	= 0;			
		
	printf("%s:%d ethbrs_list[j].priority = %d \n",__FUNCTION__, __LINE__, ethbrs_list[j].priority);
	
	pthread_mutex_unlock(&eth_mutex);	
	}
	pthread_exit(NULL);
}