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
node *temp,*temp1;
temp=new node;
temp->data=x;
temp->next=NULL;
temp1=list;
while(temp1->next!=NULL)
temp1=temp1->next;
temp1->next=temp;
temp->next=NULL;
}

void traversal()
{
node *t;
t=list;
cout<<"list after traversing is:\n";
while(t!=NULL)
{cout<<t->data<<" ";
t=t->next;
}cout<<endl;
}
void insert_aft(int y,int key1)
{node *t,*t1;
t=new node;
t->data=y;
t->next=NULL;
t1=list;
while(t1->data!=key1&&t1->next!=NULL)
t1=t1->next;
if(t1->data==key1)
{
t->next=t1->next;
t1->next=t;
}
else if(t1->next==NULL)
cout<<"element not present\n";
}
void insert_bef(int z,int key2)
{
node *t,*t1,*prev;
t=new node;
t->data=z;
t->next=NULL;
t1=list;
while(t1->data!=key2&&t1->next!=NULL)
{ prev=t1;
t1=t1->next;}
if(t1->data==key2)
{
t->next=prev->next;
prev->next=t;
}
else if(t1->next==NULL)
cout<<"element not present\n";
}
void main()
{
clrscr();
int k,n,a,b,c,d;
list=new node;
cout<<"enter no. of elements you want to have in the linked list";
cin>>n;
cout<<"enter the elements\n";
cin>>k;
list->data=k;
list->next=NULL;
for(int i=1;i<n;i++)
{
cin>>k;
push(k);
}
traversal();
node *curr,*prev,*nex;
curr=list;
prev=NULL;
while(curr!=NULL)
{
nex=curr->next;
curr->next=prev;
prev=curr;
curr=nex;
}
list=prev;
traversal();
cout<<"enter element n key for insert after";
cin>>a>>b;
insert_aft(a,b);
traversal();
cout<<"enter element n key for inset before";
cin>>c>>d;
insert_bef(c,d);
traversal();
getch();
}
