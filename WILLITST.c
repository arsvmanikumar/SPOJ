#include<stdio.h>
int main()
{
	 long long int element;
	scanf("%lld",&element);
	if((element&(element-1))==0) 
	{
		printf("TAK\n");
	}
	else
	{
		printf("NIE\n");
	}
	return 0;
}




