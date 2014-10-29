#include<stdio.h>


int main()
{
	int t,n,i,m,no,max1=-1,max2=-1;
	int *a=NULL,*b=NULL;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&n,&m);
	
		for(i=0;i<n;i++)
		{
			scanf("%d",&no);
			if(max1<no)
			{
				max1=no;
			}
			
		}
		
		for(i=0;i<m;i++)
		{	
			scanf("%d",&no);
			if(max2<no)
			{
				max2=no;
			}
		}
	if(max1>=max2)
	{
		printf("Godzilla\n");	
	}
	else
	{
		printf("MechaGodzilla\n");
	}
	max1=max2=-1;
	}
	return 0;
}


