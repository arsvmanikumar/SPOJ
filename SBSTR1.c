#include <stdio.h>
#include <stdlib.h>


char* getInput(FILE *fp,size_t size,int *str_len)
{
	char *str=NULL;
	int ch;
	size_t len=0;
	str=(char *)realloc(NULL,sizeof(char)*size);
	if(!str)
	{
		return str;
	}
	while(EOF!=(ch=fgetc(fp)) && (ch!='\n' && ch!=' '))
	{
		str[len++]=ch;
		if(len==size)
		{
			str=(char *)realloc(str,sizeof(char)*(size+=16));
		}
		if(!str)
		{
			return str;
		}
	}
	str[len++]='\0';
	*str_len=len;
	return str;
}


void isSubString(char *a,char *b,int a_len,int b_len)
{
	int i=0,j=0;

	while(i<a_len)
	{
		if(*(a+i)==*(b+j))
		{
			j++;
//			i++;
		}
		else
		{
			if(j>0)
			{
			i-=j-2;
			j=0;
			}
		}
		if(j==b_len-1)
		{
			break;
		}
		i++;
	}
		if(j==b_len-1)
		{
			return 1;
		}
	return 0;
}
int main(){

	int t=24;
	char *a,*b;
	int a_len,b_len;
	while(t--)
	{
		a=getInput(stdin,10,&a_len);
		b=getInput(stdin,10,&b_len);
		printf("%d\n",isSubString(a,b,a_len,b_len));
	}
	
	return 0;
}


