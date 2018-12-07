#include <stdio.h>
#include <string.h>

int main()
{
	printf("%d in main\n", __LINE__);
//	goto err;
	printf("%d in main\n", __LINE__);
err:
	printf("%d in err\n", __LINE__);
	
}
