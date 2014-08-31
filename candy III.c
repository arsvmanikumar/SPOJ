//candy III

#include <stdio.h>

int main(void) {
	int t,n,iterator;
	long long sum,element;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		iterator=0;
		sum=0;
		while(iterator<n)
		{
			scanf("%lld",&element);
			sum=sum%n+((element)%n);
			sum=sum%n;
			iterator++;
		}
		if(sum%n==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}

