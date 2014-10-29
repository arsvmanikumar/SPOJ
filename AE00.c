#include<stdio.h>

int main(void)
{
	int num,len,bre,count=0;
	scanf("%d",&num);
	for(len=1;len<=num;len++)
		for(bre=len;bre<=num;bre++)
			if(len*bre<=num)
				count++;
	printf("%d",count);
	return 0;
}

