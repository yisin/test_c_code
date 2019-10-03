#include <stdlib.h>
#include <stdio.h>
#if 0
typedef struct node
{
	char info;
	struct node *linkstring;
}linkstring;

linkstring *substring(linkstring *r1, int i, int j)
{
	int k;
	linkstring *p, *q, *s, *r;
	p = r1;
	k = 1;
	while(k <= i)
	{
		p = p->linkstring;
		k++;
	}
	if (p == NULL)
		printf("i is error!\n");
	else
	{
		r = (struct linkstring*) malloc(sizeof(linkstring *));
		q = r;
		k = 1;
		while(k <=j && p!=NULL)
		{
			s = (struct linkstring*)malloc(sizeof(linkstring *));
			s->info = p->info;
			q->linkstring = s;
			q = p;
			p = p->linkstring;
			k++;
		}
		q->linkstring = NULL;
		q = r;
		r= r->linkstring;
	}
	return r;
}

int main()
{

	substring("abcde", 1, 2);
}
#endif
 
 int main()
 {
 	int a[6]={2,3,-8,1,2,3};
 	int sum = 0;
 	int last_sum = 0;
 	int i = 0;
 	int keep_index[6]={0};
 	int count = 0;

 	for (i = 0; i<6; i++)
 	{
 		sum = sum + a[i];
 		printf("sum = %d\n", sum);

 		if (sum > last_sum)
 		{
 			last_sum = sum;
 			keep_index[count] = i;
 			printf("last_sum = %d\n", last_sum);
 			count ++;
 		}
 		else
 		{
 			sum = 0;
 			last_sum = 0;
 			count = 0;
 		}
 	}
 	printf("last_sum = %d\n", last_sum);
 	for (i = 0; i<6; i++)
 	{
 		printf("sum index entry = %d\n", keep_index[i]);
 	}


unsigned long v1 = 0x00001111;
unsigned long v2 = 0x00001202;
unsigned long v;
v = v1&(~v2);
printf("v = %lu\n", v);
v = v | v2;
printf("v = %lu\n", v);


		int a1[5] ={1,2,3,4,5};
		int *p = (int *)(&a1+1);
		
		printf("======*(a1+1)=%d (*p-1)=%d  (*p)=%d\n", *(a1+1), (*p-1), *p);


	int b[5]={1,2,3,4,5};
	int *ptr=(int*)(&b+1);
	printf("*ptr = %d ,&b = %p, &b[0]=%p, &b+1=%p\n", *ptr, &b, &b[0], &b+1);

	printf("*(b+1)=%d, ptr=%p, *(ptr-1)=%d *(ptr)=%d,\n", *(b+1), ptr, *(ptr-1), *(ptr));
 }