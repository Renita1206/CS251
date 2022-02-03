#include<stdio.h>
#include "server.h"

int main()
{
	//int a;
	int n;
	int count=0;
	printf("Enter term number: ");
	scanf("%d", &n);
	int res = fib_count(n, &count);
	printf("result: %d\n",res);
	printf("count: %d\n",count);
	return 0;
}
