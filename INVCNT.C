#include<stdio.h>
#include<malloc.h>

unsigned long long  merge(int arr[],int left_start,int right_start,int right_end)
{
   unsigned int *aux=(int *)malloc(sizeof(int)*(right_end-left_start+1));
    int left_end=right_start-1;
    int count=0,i=0;
    unsigned long long  no_of_inversions=0;
    int lhs=left_start;
    while(left_end >=left_start &&right_start<=right_end)
    {
        if(arr[left_start]<=arr[right_start])
        {
            aux[count++]=arr[left_start++];
             
        }
        else
        {
            aux[count++]=arr[right_start++];
            no_of_inversions+=left_end-left_start+1;
        }
    }
    
    while(left_end >=left_start)
    {
        aux[count++]=arr[left_start++];
    }
    while(right_start<=right_end)
    {
          aux[count++]=arr[right_start++];
    }
    
    for(i=0;i<count;i++)
    {
        arr[lhs+i]=aux[i];    
    }
    free(aux);
    return no_of_inversions;
}


unsigned long long  merge_sort(unsigned int arr[],int left,int right)
{
    if(right-left <= 0)
		return 0;
    int mid=(left+(right-left)/2);
    unsigned long long  l,r;
    l=merge_sort(arr,left,mid);
    r=merge_sort(arr,mid+1,right);
    return l+r+merge(arr,left,mid+1,right);
}

int main() {

    int t, n, c, m,i;
    unsigned long long  answer;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d",&n);
       unsigned int *arr=(int *)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%u",&arr[i]);
        answer = merge_sort(arr,0,n-1); 
       // print_array(arr,n);
        printf("%llu\n",answer);
        
    }
    return 0;
}