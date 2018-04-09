#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <dmalloc.h>

typedef struct _ob_status{
	char neighmac[20];
	int obstatus;
}ob_status,*ptr_obstatus;


int test(ob_status **P1, int *value) {

	if(*P1 == NULL) {
		printf("%s: P1 is NULL\n", __FUNCTION__);
	}

	ob_status *Pobstatus = NULL;
	Pobstatus = (struct _ob_status *)malloc(2 *sizeof(struct _ob_status));
	memset(Pobstatus, 0x0A, sizeof(Pobstatus));
	*P1 = (struct _ob_status *) Pobstatus;


	memcpy(Pobstatus[0].neighmac, "11:22:33:44:55:66", sizeof(Pobstatus[0].neighmac));

	*value = 123;

	printf("P1 = %p,Pobstatus= %p, Pobstatus[0].neighmac[0] = %02X\n", &(*P1), &Pobstatus, Pobstatus[0].neighmac[0]);

}


int main() {

	ob_status *P1 = NULL;
	int value = 0;
	
	test(&P1, &value);

	printf("P1 = %p, test = %d, P1[0].neighmac[0] = %02X\n", &P1, value, P1[0].neighmac[0]);
	if (P1 != NULL) {
		printf("release memory\n");
		free(P1);
	}
}

