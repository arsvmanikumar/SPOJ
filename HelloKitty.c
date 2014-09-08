#include<stdio.h>

int size_array(char *arr)
{
	int iterator=0;
	while(*arr!=NULL)
	{
		iterator++;
		arr=arr+1;
	}
	return iterator;
}
void HelloKitty(char arr[],int n,int arr_size)
{
	int i=0,j=0,k=0,iterator=0;
	for(iterator=0;iterator<arr_size;iterator++)
	{
		for(i=0;i<n;i++)
		{
			for(k=iterator;k<arr_size;k++)
			{
				printf("%c",arr[k]);
			}
			for(j=0;j<iterator;j++)
			{
				printf("%c",arr[j]);
			}
		}
		printf("\n");

	}
}



int main()
{
char arr[50];
int length=0,n=0;
while(1)
{
	scanf("%s",arr);
	scanf("%d",&n);

	if(arr[0]=='.')
		break;
	length=size_array(arr);
	printf("%s  %d %d\n",arr,n,length);
	HelloKitty(arr,n,length);
	
}

return 0;
}