#include<stdio.h>
#include "server.h"

int power(int a, int n)
{
	if(n==0)
		return 1;
	else
		return a*(power(a,n-1));
}

int power_count(int a, int n, int* count)
{
	(*count)++;
	if(n==0)
		return 1;
	else
		return a*(power_count(a,n-1, count));
}

int fib_count(int n,  int* count)
{
	(*count)++;
    	if(n==0)
        	return 0;
    	else if(n==1 || n==2)
        	return 1;
    	else
        	return fib_count(n-1, count)+fib_count(n-2, count);
}

