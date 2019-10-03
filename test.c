#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MUX(a,b) a*b
int fun(int x)

{

   int count = 0 ;

   printf("%s:%d x = %d\n", __FUNCTION__, __LINE__, x);
   while(x){

      count++ ;
   	  printf("%s:%d x = %d\n", __FUNCTION__, __LINE__, x);
      x = x & (x-1) ;
   	  printf("%s:%d x = %d\n", __FUNCTION__, __LINE__, x);

   }

  printf("%s:%d count = %d\n", __FUNCTION__, __LINE__, count);

   return count ;

}      

int c;

int fib(int n)
{
	//printf("c = %d, n = %d\n", c, n);
    c++;
    int tmp = 0;
    if ((n==1)|| (n==2))
      return 1;

	printf("c = %d, n = %d\n", c, n);

	tmp = fib(n-1)+fib(n-2);
	printf("fib(%d)+fib(%d) = %d\n", n-1, n-2, tmp);
	//printf("fib(%d) %d\n", n-1, tmp);
    //return (fib(n-1)+fib(n-2)); 
    return tmp;

}

int cal_space(char *s1)
{

  printf("s1 = %s\n", s1);

  int space = 0;

    if(space == 0 && isspace(*s1)) {
        printf("config format is incorrect.\n");
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
        printf("config format is incorrect.\n");
        return 0;
    }

    printf("parameter count = %d\n", space+1);
   return space + 1;
}

#define BIT5 (0x1<<5)
static int a;
void set_bit5(void)
{
	a = 0x20;
	printf("%s:BIT5 = %02X, a & BIT5 = %02X\n", __FUNCTION__,BIT5,  a & BIT5);
}

void clear_bit5(void)
{
	a = 0x20;
	printf("%s:BIT5 = %02X, a & BIT5 = %02X\n", __FUNCTION__, BIT5, a & ~BIT5);
}

#define ADD(x,y) x+y

typedef union {
  unsigned long l;
  unsigned char c[4];
} EndianTest;

int checkCPU()
{
	{
		union w
		{
			int a;
			char b;
		}c;
		c.a=1;

  if (c.b == 0x1) {
    printf("Little Endian\n");
  } else if (c.a == 0x1 ) 
    printf("Big Endian\n");

		return (c.b == 1);
	}
}
int main()
{
	//printf("%d\n", MUX(10,5));
	//printf("%d\n", MUX(10+5,10-5));  // 10+5*10-5 = 55

	//printf("fun = %d\n", fun(456)+fun(123)+fun(789));
#if 0
	c=0;

    fib(5);

    printf("c = %d\n", c);
#endif
#if 0
	char string[1024]={0};
	char string2[1024]={0};
 	int chkval = 0;
 	
	printf ("Enter your string: ");
	scanf("%[^\n]" , &string);
	printf("your string is %s\n", string);

	//chkval = cal_space(string);
#endif	
#if 0
	char c;
	c=getchar();
	printf("c = %d, (c!='a') = %d\n", c, (c!='a'));
	while((c!='a'))
		    putchar(c);
#endif
	int a[6], i;
	for (i = 1; i< 6; i++)
	{
		a[i] = 9*(i-2+4*(i>3))%5;
		printf("%2d", a[i]);
	}

	printf("a5>>2 = %02X\n", ~0xa5 >> 2);

	set_bit5();
	clear_bit5();

	int m=3;
	m+=m*ADD(m,m);
	printf("m+=m*ADD(m,m) = %d\n", m);



  EndianTest et;
  et.l = 0x12345678;
  printf("This system is:");
  if (et.c[0] == 0x78 && et.c[1] == 0x56 && et.c[2] == 0x34 && et.c[3] == 0x12) {
    printf("Little Endian\n");
  } else if (et.c[0] == 0x12 && et.c[1] == 0x34 && et.c[2] == 0x56 && et.c[3] == 0x78) {
    printf("Big Endian\n");
  } else {
    printf("Unknown Endian\n");
  }
  printf("0x%lX memory sequence:\n", et.l);
  for (int i = 0; i < 4; i++) {
    printf("%p : 0x%02X\n", &et.c[i], et.c[i]);
  }

	checkCPU();


	int b[5]={1,2,3,4,5};
	int *ptr=(int*)(&b+1);
	printf("*ptr = %d ,&b = %p, &b[0]=%p, &b+1=%p\n", *ptr, &b, &b[0], &b+1);

	printf("%d, %d %d\n", *(b+1), *(ptr-1), *(ptr));
  return 0;

}