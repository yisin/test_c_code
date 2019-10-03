#include <stdio.h>

int main() {

    int number[10] = {9,2,3,1,5,4,8,7,10,6};
    int i = 0, j = 0, k =0;
    int temp = 0;


    for( k = 0; k < 10; k++ ) {
        printf("%d ", number[k]);
    }
    printf("\n");
    printf("======Start sort======\n");

    for( i = 0; i < 10; i++) {
        for( j = i; j < 10; j++) {
        printf(" number[j=%d](%d),  number[i=%d](%d)\n",  j, number[j], i , number[i]);

            if( number[j] > number[i] )
            {
                printf("=======Change address======\n");
                temp = number[j];
                number[j] = number[i];
                number[i] = temp;

                for( k = 0; k < 10; k++ ) {
                    printf("%d ", number[k]);
                }
                printf("\n");

            }
        }
    }

    for( i = 0; i < 10; i++ ) {
        printf("%d ", number[i]);
    }
    printf("\n");

return 0;
}