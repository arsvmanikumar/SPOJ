// FASHION.cpp : Defines the entry point for the console application.
//

/*
A fashion show rates participants according to their level of hotness. Two different fashion shows were organized, one for men and the other for women. A date for the third is yet to be decided ;) .

Now the results of both fashion shows are out. The participants of both the fashion shows have decided to date each other, but as usual they have difficuly in choosing their partners. The Maximum Match dating serive (MMDS) comes to their rescue and matches them in such a way that that maximizes the hotness bonds for all couples.

If a man has been rated at hotness level x and a women at hotness level y, the value of their hotness bond is x*y.

Both fashion shows contain N participants each. MMDS has done its job and your job is to find the sum of hotness bonds for all the couples that MMDS has proposed.

Input

The first line of the input contains an integer t, the number of test cases. t test cases follow.

Each test case consists of 3 lines:

The first line contains a single integer N (1 <= N <= 1000).
The second line contains N integers separated by single spaces denoting the hotness levels of the men.
The third line contains N integers separated by single spaces denoting the hotness levels of the women.
All hotness ratings are on a scale of 0 to 10.

Output

For each test case output a single line containing a single integer denoting the sum of the hotness bonds for all pairs that MMDS has proposed.

Example

Input:
2
2
1 1
3 2
3
2 3 2
1 3 2

Output:
5
15
*/

#include<stdio.h>
#include<malloc.h>

void insertion_sort(int arr[],int n)
{
	int iterator1=1,iterator2;
	while(iterator1<n)
	{
		iterator2=iterator1-1;
		int temp=arr[iterator1];
		while(iterator2>=0 && arr[iterator2] > temp)
		{
			arr[iterator2+1]=arr[iterator2];
			iterator2--;
		}
		arr[iterator2+1]=temp;
		iterator1++;
	}
}


int fashion_main(int men[],int women[],int n)
{
	int sum=0;
	insertion_sort(men,n);
	insertion_sort(women,n);
	for(int i=0;i<n;i++)
	{
		sum+=men[i]*women[i];
	}
	return sum;
}

int main(int argc, _TCHAR* argv[])
{
	int t,n;
	int *men=NULL,*women=NULL;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		men=(int *)malloc(sizeof(int)*n);
		women=(int *)malloc(sizeof(int)*n);
		for(int i=0;i<n;i++)
			scanf("%d",(men+i));
		for(int i=0;i<n;i++)
			scanf("%d",(women+i));
		printf("%d\n",fashion_main(men,women,n));
		free(men);
		free(women);
	}
	return 0;
}

