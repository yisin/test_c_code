#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



static char *rand_string(char *str, int size)
{
    int n = 0;
    int ts = time((time_t *)NULL);
    unsigned int key = 0;
    int ra = 0;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (size) {
        --size;
        for (n = 0; n < size; n++) {
             ra = rand();
             printf("ra = %d, ts = %d\n", ra, ts);
             key = (ra/2 + ts/2) % (int) (sizeof charset - 1);
             printf("key = %d\n", key);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

int main() {

    char str[33] ={0};
    rand_string(str, 33);
    printf("str = %s\n", str);

}