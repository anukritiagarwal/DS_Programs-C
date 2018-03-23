#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
struct node
{
int data;
struct node*link;
};
void addatbeg(struct node**,int);
void display(struct node*);
void reverse(struct node**);
void addafter(struct node*,int,int);
void del(struct node**,int);
void addbef(struct node*,int,int);
int main()
{
struct node *p;
p=NULL;
addatbeg(&p,7);
addatbeg(&p,43);
addatbeg(&p,17);
addatbeg(&p,3);
clrscr();
display(p);
addafter(p,2,1);
display(p);
addbef(p,2,32);
display(p);
del(&p,17);
display(p);
reverse(&p);
display(p);
getch();
return 0;
}
void addatbeg(struct node**q,int num)
{
struct node*temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=num;
temp->link=*q;
*q=temp;
}
void reverse(struct node**x)
{
struct node*r,*q,*s;
q=*x;
r=NULL;
while(q!=NULL)
{
s=r;
r=q;
q=q->link;
r->link=s;
}
*x=r;
}
void display(struct node*q)
{
printf("\n");
while(q!=NULL)
{
printf("%d ",q->data);
q=q->link;
}
}
void addafter(struct node*q,int loc,int num)
{
struct node*temp,*r;
int i;
temp=q;
for(i=0;i<loc;i++)
{
temp=temp->link;
if (temp==NULL)
{
printf ("\n there are less than %d elements in list",loc);
return;
}
r=(struct node*)malloc(sizeof(struct node));
r->data=num;
r->link=temp->link;
temp->link=r;
}
void addbef(struct node*q,int loc,int num)
{
struct node*temp,*r;
int i;
temp=q;
for(i=0;i<loc-1;i++)
{
temp=temp->link;
if(temp==NULL)
{
printf("\n there are less than %d elements in list",loc);
return;
}
r=(struct node*)malloc(sizeof(struct node));
r->data=num;
r->link=temp->link;
temp->link=r;
}
void del(struct node**q,int num)
{
struct node*old,*temp;
temp=*q;
while(temp!=NULL)
{
if (temp->data==num)
{
if (temp==*q)
*q=temp->link;
else
old->link=temp->link;
free(temp);
return;
}
else
{
old=temp;
temp=temp->link;
}
}
printf("\n element %d not found",num);
}
