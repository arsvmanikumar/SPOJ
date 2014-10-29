#include <stdio.h>

long int gcd(long int a,long int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(void) {
	// your code goes here
	int testcases;
	long int a,b,gcd_result;
	
	scanf("%d",&testcases);
	while(testcases--)
	{
		scanf("%ld%ld",&a,&b);	
		gcd_result=a>b?gcd(a,b):gcd(b,a);
		printf("%d %d\n",b/gcd_result,a/gcd_result);
	}
	
	return 0;
}
