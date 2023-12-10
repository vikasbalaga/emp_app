#include<stdio.h>
#include"functions.h"
#include<stdlib.h>
void main()
{
	int u;
	int id;
char name[25],pos[25];
while(1)
{
printf("\nMENU\n");
printf("1.ADD EMPLOYEE\n");
printf("2.DELETE EMPLOYEE\n");
printf("3.SEARCH EMPLOYEE\n");
printf("4.LIST EMPLOYEES\n");
printf("5.QUIT\n");
printf("PRESS YOUR CHOICE\n");
scanf("%d",&u);
switch(u)
{
case 1:
printf("enter employee details\n");
printf("enter employee name\n");
scanf("%s",name);
printf("enter employee pos\n");
scanf("%s",pos);
id=add_emp(name,pos);
printf("employee id is %d\n",id);
break;
case 2:
printf("enter employee id\n");
scanf("%d",&id);
del_emp(id);
break;
case 3:
printf("enter employee id\n");
scanf("%d",&id);
search_emp(id);
break;
case 4:
list_emps();
break;
case 5:
exit_app();
}
}
}