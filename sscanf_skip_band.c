#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _signal_handler {
  int bandIndex;
  int bandWidth;
  int rssi_threshold;
}signal_handler;

int n = 0;
extern struct _signal_handler default_signal_handlers[];

struct _signal_handler default_signal_handlers[] = {
  {0,  20, -60},
  {0,  40, -70},
  {1,  20, -80},
  {1,  40, -85},
  {1,  80, -90},
  {2,  20, -81},
  {2,  40, -86},
  {2,  80, -91},
  {0,   0,   0}
};

signal_handler *sig_entry = NULL;

int cal_space(char *s1)
{

  printf("s1 = %s\n", s1);

  int space = 0;

    if(space == 0 && isspace(*s1)) {
        printf("signal_defined format is incorrect.\n");
        return 0;
    }

    while (*s1)
    {
       if (isspace(*s1))
       {
           space++;
       }
       s1++;
    }
    s1--;
    if(isspace(*s1)) {
        printf("signal_defined format is incorrect.\n");
        return 0;
    }

    printf("space = %d\n", space);
   return space + 1;
}




int main(int argc, char **argv)
{
  //char signal_defined[]="0 20 -62 0 40 -72 1 20 -82 1 40 -86 1 80 -91 2 20 -82 2 40 -87 2 80 -92";
  //char signal_defined[]="0 20 -62 0 40 -72 1 20 -82 1 40 -86 1 80 -91 2 20 -82 2 40 -87 2 80 -92";
  char signal_defined[]="0 20 -62 0 40 -72 1 20 -82 1 40 -86 1 80 -91";
  char *sigReq = signal_defined;
 //char *sigReq = NULL;
  int chkval = 0, count = 0, offset = 0;
  div_t entry;

  struct _signal_handler *handler = NULL;
  struct _signal_handler *handler_entry = NULL;
  //struct _signal_handler *handler_entry = &default_signal_handlers[0];

  if (sigReq == NULL) {
    printf("sigReq is null, set to default sigReq.\n");
    handler_entry = &default_signal_handlers[0];
  }
  else
  {
    chkval = cal_space(sigReq);
    printf("sigReq length = %d\n", chkval);


    entry = div(chkval, 3);
    printf("Quo = %d, rem = %d\n", entry.quot, entry.rem);

    if (entry.rem != 0 || entry.quot == 0) {
      printf("sigReq is incorrect, use default sigReq.\n");
      handler_entry = &default_signal_handlers[0];
    }
    else {
      printf("sigReq is OK.\n");

      sig_entry = (struct _signal_handler *) malloc((entry.quot+1) *sizeof(struct _signal_handler));

      if (sig_entry == NULL) {
        printf("can't alloc memory\n");
        return 0;
      }
      memset(sig_entry,0x00,(entry.quot+1) *sizeof(struct _signal_handler));

      while (sscanf(sigReq, " %d%d%d%n", &sig_entry[count].bandIndex, &sig_entry[count].bandWidth, &sig_entry[count].rssi_threshold, &offset) == 3)
      {
        sigReq += offset;
        printf("read: %d %d %d\n", sig_entry[count].bandIndex,sig_entry[count].bandWidth, sig_entry[count].rssi_threshold);

        if (count < entry.quot)
            count++;
      }
      handler_entry = &sig_entry[0];
    }

  }



  printf("%s:%d\n", __FUNCTION__, atoi(argv[1]));
  n = atoi(argv[1]);
  for (handler = handler_entry; handler->bandWidth; handler++) {
    printf("%s n = %d,  handler->rssi_threshold = %d\n", __FUNCTION__,  n, handler->rssi_threshold);
   // if (handler->rssi_threshold == n)
      if (handler->bandWidth == n)
        printf("%s bandIndex = %d,   handler->bandWidth = %d, handler->rssi_threshold = %d\n", __FUNCTION__,   handler->bandIndex ,  handler->bandWidth, handler->rssi_threshold);
  }

  if (sig_entry != NULL)
      free(sig_entry);

    return 0;

}