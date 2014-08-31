#include <stdio.h>


int size_of_string(char *str)
{
	int count=0;
	while(*str!=0)
	{
		count++;
		str=str+1;
	}
	return count;
}


int main(void) 
{
	int t,count,iterator,iterator2,str_length;
	long long result;
	char str[31];
	scanf("%d",&t);//no of test cases input
	while(t--)
	{
		scanf("%s",str);
		
		str_length=size_of_string(str);
		iterator=0;
		result=1;
		while(iterator<str_length)
		{
			iterator2=iterator+1;
			count=0;
			while(str[iterator]==str[iterator2])
			{
				count++;
				iterator2++;
			}
			if(count>0)
			{
				result*=1<<count;
			
			}
				iterator+=count+1;			
		}
		printf("%lld\n",result);

	}
	return 0;
}


