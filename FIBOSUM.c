#include<stdio.h>

unsigned long long MOD=1000000007;

long long int fib_matrix_multiplication(long long int n)
{
	long long int a[2][2]={{1,0},{0,1}};
	long long int temp[2][2]={{0,0},{0,0}};
	long long int result[2][2]={{1,1},{1,0}};
	int i,j,k;
	while(n>0)
	{
		if(n&1)
		{
			for(i=0;i<2;i++)
					for(j=0;j<2;j++)
						temp[i][j]=0;
			for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					for(k=0;k<2;k++)
						temp[i][j]=(temp[i][j]+(a[i][k]%MOD)*(result[k][j]%MOD))%MOD;
						
			for(i=0;i<2;i++)
				for(j=0;j<2;j++)
					a[i][j]=temp[i][j];

	}
				for(i=0;i<2;i++)
					for(j=0;j<2;j++)
						temp[i][j]=0;
				for(i=0;i<2;i++)
					for(j=0;j<2;j++)
						for(k=0;k<2;k++)
						temp[i][j]=(temp[i][j]+(result[i][k]%MOD)*(result[k][j]%MOD))%MOD;
				for(i=0;i<2;i++)
					for(j=0;j<2;j++)
						result[i][j]=temp[i][j];	
				n=n/2;
	}
	return a[0][1];
}

int main()
{
	int t,m,n;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",(fib_matrix_multiplication(n+2)-fib_matrix_multiplication(m+1)+MOD)%MOD);
	
	}return 0;
}

