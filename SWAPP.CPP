#include<iostream.h>
#include<conio.h>
struct node
{
int data;
node *next;
};
node *list;
void push(int x)
{
node *t,*t1;
t=new node;
t->data=x;
t->next=NULL;
t1=list;
while(t1->next!=NULL)
t1=t1->next;
t1->next=t;
t->next=NULL;
}
void traversal()
{
node *t;
t=list;
while(t!=NULL)
{
 cout<<t->data<<" ";
 t=t->next;
}}
void swapp(int key)
{
node *prev=NULL,*t1=NULL;
t1=list;
while(t1->next->data!=key&&t1->next->next!=NULL)
{prev=t1;
t1=t1->next;
}
if(t1->next->data==key)
{
prev->next=t1->next;
t1->next=t1->next->next;
prev->next->next=t1;
}
else if(t1->next==NULL)
cout<<"key not found";
}
 void main()
 {
 clrscr();
 int k,n,z;
 cout<<"enter no. of elements you want to have in your linked list\n";
 cin>>n;
 cout<<"enter elements\n";
 cin>>k;
 list=new node;
 list->data=k;
 list->next=NULL;
 for(int i=1;i<n;i++)
 { cin>>k;
 push(k);
 }
 traversal();
 cout<<"enter no. for swapping\n";
 cin>>z;
 swapp(z);
 traversal();
getch();
}

