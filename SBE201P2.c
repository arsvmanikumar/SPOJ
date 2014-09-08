
#include <stdio.h>
#include<malloc.h>

struct list
{
	int data;
	struct list *next;
};
void print(struct list *head)
{
	if(head==NULL)
	{
		printf("empty\n");
		return;
	}
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

struct list* front(struct list *head,int data)
{
	struct list *temp=(struct list *)malloc(sizeof(struct list));
	temp->data=data;
	temp->next=head;
	return temp;
}

struct list* insert(struct list *head,int M,int data)
{
	int iterator=0;
	struct list *temp=NULL,*node=head;
	while(iterator<M&&head!=NULL)
	{
		temp=head;
		head=head->next;
		iterator++;
	}
	if(temp==NULL)
	{
		return front(head,data);
	}
	else
	{
		temp->next=front(head,data);
	}
	return node;
}

struct list* delete1(struct list *head)
{
	if(head==NULL)
		return NULL;
	struct list *temp=head->next;
	free(head);
	return temp;
}

struct list* delete_index(struct list *head,int M)
{
	int iterator=0;
	struct list* temp=NULL,*node=head;;
	while(iterator<M&&head!=NULL)
	{
		temp=head;
		head=head->next;
		iterator++;
	}
	if(temp==NULL)
		return delete1(head);
	else
		temp->next=delete1(head);
	return node;
}

int main()
{	
	char ch,tmp;
	int data,m;
	struct list *head=NULL;

	int is_quit=1;
	while(is_quit)
	{
		scanf("%c",&ch);
		switch(ch)
		{
			case 'f':scanf("%d",&data);
					head=front(head,data);
					break;
			case 'i':scanf("%d %d",&m,&data);
					head=insert(head,m,data);
					break;
			case 'r':head=delete1(head);
					break;
			case 'd':scanf("%d",&m);
					head=delete_index(head,m);
					break;
			case 'q':is_quit=0;
						break;
					
		}
		print(head);
		scanf("%c",&tmp);
	}
	return 0;
}



