#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<iostream.h>

struct node{
int data;
struct node *link;
};

void app(struct node**,int);
//void in(struct node**,int);
void disp(struct node*,int);
int main()
{
clrscr();
struct node *p,*q;
int m,n,i,a;
p=q=NULL;
printf("enter degree of 1st polynomial");
scanf("%d",m);
printf("enter coefficients");
for(i=0;i<=m;i++)
{
scanf("%d",&a);
app(&p,a);
}
disp(p,m);

//in(&p,m);
printf("enter degree of 2nd polynomial");
scanf("%d",n);
for(i=0;i<=n;i++)
{
scanf("%d",&a);
app(&q,a);
}
//in(&q,n);
//disp(p,m);
disp(q,n);
getch();
return 0;
}
//void in(struct node**l,int f)
//{
//int i,a;
//printf("enter degree of the polnomial");
//scanf("%d",&n);
//for(i=0;i<=f;i++)
//{
//scanf("%d",&a);
//app(&l,a);
//}
//}
void app(struct node**l,int a)
{
struct node *temp,*r;
if(*l==NULL)
{
temp=(struct node*)malloc(sizeof(struct node));
temp->data=a;
temp->link=NULL;
*l=temp;
}
else
{
temp=*l;
while(temp->link!=NULL)
temp=temp->link;
r=(struct node*)malloc(sizeof(struct node));
r->data=a;
r->link=NULL;
temp->link=r;
}
}
void disp(struct node*l,int f)
{
printf("\n");
while(l!=NULL)
{
printf("%dx^f+",l->data);
l=l->link;
f--;
}
}