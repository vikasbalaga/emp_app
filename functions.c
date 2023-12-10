#include<stdio.h>
#include"functions.h"
#include"linked_list.h"
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct node*head;
static bool flag;
int rec;
void caller()
{
	if(!flag)
	{
		create();
		flag=true;
	}
}
void create()
{
struct node*c;
        head=(struct node*)malloc(sizeof(struct node));
head=NULL;
FILE*fp=fopen("database.txt","r");
if(fp==NULL)
{
	rec=0;
}
else
{
while(1)
{
int id;
char name[25],pos[25];
fscanf(fp,"%d",&id);
fscanf(fp,"%s",name);
fscanf(fp,"%s",pos);
struct node*emp=(struct node*)malloc(sizeof(struct node));
emp->id=id;
strcpy(emp->name,name);
strcpy(emp->pos,pos);

if(head==NULL)
{
	head=emp;
}
else
{
c=head;
while(c->next!=NULL)
{
	c=c->next;
}
c->next=emp;
c=emp;
emp->next=NULL;
}
if(fgetc(fp)==EOF)
{
	rec=emp->id;
	break;
}
}
fclose(fp);
}
}
int add_emp(char*name,char*pos)
{
caller();
head=add(head,&rec,name,pos);
return rec;
}
void del_emp(int id)
{
caller();
head=del(head,&rec,id);
}

void search_emp(int id)
{
caller();
search(head,id);
}
void list_emps()
{
    caller();
	list(head);
};
void save_data()
{
	if(flag!=0)
	{
	struct node*p=(struct node*)malloc(sizeof(struct node));
	p=head;
	if(p!=NULL)
	{
	FILE*fp=fopen("database.txt","w");
	while(p!=NULL)
	{
	fprintf(fp,"%d %s %s",p->id,p->name,p->pos);
	p=p->next;
	if(p!=NULL)
		fprintf(fp,"\n");
	}
	fclose(fp);
	}
	else
		remove("database.txt");
	free(p);
	}
	exit(0);
}
void exit_app()
{
	save_data();
}

	