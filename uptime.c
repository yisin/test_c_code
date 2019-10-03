#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include<unistd.h>

struct timeval timeget(void)
{
    struct timeval now;
    unsigned char  timestr[60] = {0};
    unsigned char  uptimestr[30] = {0};
    unsigned char * dotaddr;
    unsigned long second;
    char error = 0;
    FILE * timefile = NULL;

    timefile = fopen("/proc/uptime", "r");
    if(!timefile)
    {
        printf("[%s:line:%d] error opening '/proc/uptime'",__FILE__,__LINE__);
        error = 1;
        goto out;
    }

    if( (fread(timestr, sizeof(char), 60, timefile)) == 0 )
    {
        printf("[%s:line:%d] read '/proc/uptime' error",__FILE__,__LINE__);
        error = 1;
        goto out;
    }

    dotaddr = strchr(timestr, '.');
    if((dotaddr - timestr + 2) < 30)
    {
        memcpy(uptimestr, timestr, dotaddr - timestr + 2);
        printf("uptimestr = (%s)\n", uptimestr);
    }
    else
    {
        printf("[%s:line:%d] uptime string is too long",__FILE__,__LINE__);
        error = 1;
        goto out;
    }
    uptimestr[dotaddr - timestr + 2] = '\0';
    printf("uptimestr = (%s)\n", uptimestr);

out:
    if(error)
    {
        now.tv_sec  = 0;
        now.tv_usec = 0;
    }
    else
    {
        now.tv_sec  = atol(uptimestr);
        now.tv_usec = 0;
    }

    fclose(timefile);
    return now;
}

int main()
{
    struct timeval base_uptime;
    struct timeval uptime;

    base_uptime.tv_sec = 0;
    uptime.tv_sec = 0;

    base_uptime = timeget();
    printf("uptime = %lu\n", base_uptime.tv_sec);

    sleep(10);

    uptime = timeget();
    printf("uptime = %lu\n", uptime.tv_sec);
    return 0;
}
