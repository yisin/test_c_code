#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct _ob_status{
    unsigned char neighmac[20];
    unsigned char modelname[64];
    int obstatus;       //1 (OB_OFF),  2 (OB_Available), 3 (OB_REQ), 4 (OB_LOCKED), 5 (OB_SUCCESS)
    int timestamp;
}ob_status,*ptr_obstatus;

#if 1
unsigned remove_unnessary_data(ob_status *P_obstatus, ob_status *P_obsata, unsigned nItem)
{

    unsigned i = 0, last_pos=0;
    int j =0;
    int skip = 0;

    if(P_obstatus==NULL)
        return 0U;

    for(i=0; i<nItem; i++)
    {

        printf("i = %d\n", i);
        printf("P_obstatus[%d].neighmac(%s) , P_obstatus[%d].obstatus = %d\n",i, P_obstatus[i].neighmac, i, P_obstatus[i].obstatus);

        if(strlen(P_obstatus[i].neighmac) == 0 ||  P_obstatus[i].obstatus == 0)
            continue;

        if (i == 0) {
            memcpy(P_obsata[i].neighmac, P_obstatus[i].neighmac, sizeof(P_obsata[i].neighmac));
            memcpy(P_obsata[i].modelname, P_obstatus[i].modelname, sizeof(P_obsata[i].modelname));
            P_obsata[i].obstatus = P_obstatus[i].obstatus;
            P_obsata[i].timestamp = P_obstatus[i].timestamp;

            printf("Add new entry P_obstatus[%d].neighmac  = %s is add to P_obsata[%d].neighbmac = %s\n", i, P_obsata[j].neighmac, i, P_obsata[i].neighmac);
            last_pos++;
        }
        else {
            for(j=0; j<5; j++) 
            {
 printf("P_obsata[%d].neighmac(%s) , strlen(P_obsata[%d].neighmac) = %d\n",j, P_obsata[j].neighmac, j, strlen(P_obsata[j].neighmac));
                 skip = 0;
                 if(strlen(P_obsata[j].neighmac) != 0 && !memcmp(P_obstatus[i].neighmac, P_obsata[j].neighmac, sizeof(P_obstatus[i].neighmac))) 
                {

                    if (P_obstatus[i].obstatus != P_obsata[j].obstatus) {
                        printf("P_obstatus[%d].obstatus(%d) is different with P_obsata[%d].obstatus(%d).\n", i, P_obstatus[i].obstatus, j, P_obsata[j].obstatus);
                        skip = 0;
                    }
                    else {
                       printf("P_obstatus[%d].neighmac  = %s is add to P_obsata[%d]\n",i, P_obsata[j].neighmac, j);
                       skip = 1;
                    }
                    break;
                }

            }

            if (skip == 0) {
                memcpy(P_obsata[last_pos].neighmac, P_obstatus[i].neighmac, sizeof(P_obsata[last_pos].neighmac));
                memcpy(P_obsata[last_pos].modelname, P_obstatus[i].modelname, sizeof(P_obsata[last_pos].modelname));
                P_obsata[last_pos].obstatus = P_obstatus[i].obstatus;
                P_obsata[last_pos].timestamp = P_obstatus[i].timestamp;

                printf("Add new entry P_obstatus[%d].neighmac(%s) is add to P_obsata[%d].neighbmac = %s\n", i, P_obstatus[i].neighmac, last_pos, P_obsata[last_pos].neighmac);
                last_pos++;
            }


        }
         

        printf("#####################################\n");
        for(j=0; j<5; j++) {
            printf("j = %d %s\n", j, P_obsata[j].neighmac);
        }
         printf("#####################################\n");
    }

        return last_pos;   
}

int main()
{
    int i = 0, cnt = 0;
    ob_status *Pobstatus = NULL;
    ob_status *Pobdata = NULL;
    Pobstatus = (struct _ob_status *) malloc(5 *sizeof(struct _ob_status));
    Pobdata = (struct _ob_status *) malloc(5 *sizeof(struct _ob_status));
    memset(Pobstatus, 0x00, 5 *sizeof(struct _ob_status));
    memset(Pobdata, 0x00, 5 *sizeof(struct _ob_status));

    for (i=0; i<5; i++) {
        if (i < 2)
            memcpy(Pobstatus[i].neighmac, "11:22:33:44:55", sizeof(Pobstatus[i].neighmac));
        else 
            memcpy(Pobstatus[i].neighmac, "22:22:33:44:55", sizeof(Pobstatus[i].neighmac));
        memcpy(Pobstatus[i].modelname, "RT-AC68U", sizeof(Pobstatus[i].neighmac));
        Pobstatus[i].obstatus = 1;
        Pobstatus[i].timestamp = 12345;
    }


    cnt = remove_unnessary_data(Pobstatus, Pobdata, 5);
    printf("cnt = %u\n", cnt);
    for(i=0; i<cnt; i++) {
        printf("i = %d %s %s %d %d\n", i, Pobdata[i].neighmac, Pobdata[i].modelname, Pobdata[i].obstatus, Pobdata[i].timestamp);
    }

    free(Pobstatus);
    free(Pobdata);
    return 0;
}
#endif
#if 0
unsigned remove_dumped_memory(int *array, unsigned nItem)
{
    unsigned i, last_pos=0;
    
    if(array==NULL)
        return 0U;
    for(i=1; i<nItem; ++i) {
        if(array[i]!=array[i-1])
            array[last_pos++] = array[i-1];
    }
    if(last_pos==0 || array[last_pos-1]!=array[nItem-1])
        array[last_pos++] = array[nItem-1];
    return last_pos;
}

int main()
{    
    int array[] = {1,1,2,2,2,3,5,8,9};
    unsigned n = sizeof(array) / sizeof(array[0]);
    unsigned i, cnt;

    cnt = remove_dumped_memory(array, n);
    printf("cnt = %u\n", cnt);
    for(i=0; i<cnt; ++i)
        printf("%d\n", array[i]);
    getchar();
    return 0;
}
#endif