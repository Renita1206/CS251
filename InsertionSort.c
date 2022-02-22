#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[100];
	int size;
	//printf("Enter size: ");
	//scanf("%d",&size);
	for(int i=0; i<5; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<(size-1); i++)
	{
		int v = a[i];
		int j = i-1;
		while(j>=0)
		{
			if(a[j]>v)
			{
				v=a[j];
				a[j]=a[i];
				j=j-1;
			}
		}
		a[i]=v;
	}
	for(int i=0; i<5; i++)
		printf("%d ",a[i]);
	return 0;
}
