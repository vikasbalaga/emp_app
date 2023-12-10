#include<stdio.h>
#include"linked_list.h"
#include<string.h>
#include<stdlib.h>
struct node* add(struct node*head,int*adr,char*name,char*pos)
{
struct node*p=(struct node*)malloc(sizeof(struct node));
(*adr)++;
p->id=*adr;
strcpy(p->name,name);
strcpy(p->pos,pos);
p->next=NULL;
if(head==NULL)
{
	head=p;
}
else
{
struct node*c;
c=head;
while(c->next!=NULL)
	c=c->next;
c->next=p;
}
return head;
}
struct node* del(struct node*head,int *adr,int id)
{
	if(head!=NULL)
	{
		struct node*p;
		struct node*temp;
		p=temp=head;
		if(head->id==id)
		{
			head=head->next;
		}
		else
			p=p->next;
		while(p!=NULL)
		{
			if(p->id!=id)
			{
				temp=p;
				p=p->next;
			}
			else
				break;
		}
		if(p==NULL)
			printf("employee not found\n");
		else
		{
			temp->next=p->next;
			if(p->next==NULL)
			*adr=(p->id)-1;
		    free(p);
		}
	}
	else
		printf("employee list is empty\n");
	return head;
}
void search(struct node*head,int id)
{
struct node*p;
p=head;
if(head!=NULL)
{
while(p->id!=id)
{
	p=p->next;
	if(p==NULL)
		break;
}
if(p==NULL)
{
	printf("employee not found\n");
}
else
{
	printf("employee found\n");
printf("%d,%s,%s\n",p->id,p->name,p->pos);
}
}
else
	printf("employee list is empty\n");
}
void list(struct node*head)
{
	struct node*p;
	p=head;
	if(head!=NULL)
	{
	while(p!=NULL)
	{
		printf("%d,%s,%s",p->id,p->name,p->pos);
		printf("\n");
		p=p->next;
	}
	}
	else
		printf("employee list is empty\n");
}
