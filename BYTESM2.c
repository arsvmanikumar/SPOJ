#include <stdio.h>

int max(int a,int b)
{
	return a>b?a:b;
}

int main(void) {
	int arr[100][100];
	int result[100][100];
	int t,h,w,k,p,maximum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&w);
		for(k=0;k<h;k++)
			for(p=0;p<w;p++)
				scanf("%d",&arr[k][p]);
		for(p=0;p<w;p++)
			result[h-1][p]=arr[h-1][p];
		for(k=h-2;k>=0;k--)
			for(p=0;p<w;p++)
			{
				if(p==0)
				{
					result[k][p]=arr[k][p]+max(result[k+1][p],result[k+1][p+1]);
				}
				else if(p==w-1)
				{
					result[k][p]=arr[k][p]+max(result[k+1][p],result[k+1][p-1]);
				}
				else
					result[k][p]=arr[k][p]+max(result[k+1][p],max(result[k+1][p+1],result[k+1][p-1]));
		
			}
			maximum=0;
			for(p=0;p<w;p++){
				if(maximum<result[0][p])
				maximum=result[0][p];
			}
			printf("%d\n",maximum);
	}
	return 0;
}
