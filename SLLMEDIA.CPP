/*9. given a single, sorted linked list, find the median of the linked list*/

#include<iostream.h>
#include<conio.h>

class node
{
public:
int data;
node *link;
};

class sll
{
public:
node *first;
int len;
sll()
{
first=NULL;
len=0;
}

void add(int x);
int find(int pos);
};

void sll::add(int x)
{
node *temp,*p;
temp=new node;
temp->data=x;
if(first==NULL)
{
temp->link=first;
first=temp;
}
else
{
for(p=first;p->link!=NULL;p=p->link);
p->link=temp;
temp->link=NULL;
}
len++;
}

int sll::find(int pos)
{
int i;
if(pos<1||pos>len)
cout<<"out of bonds";
else
{
node *p;
p=first;
for(i=1;i<pos;i++)
p=p->link;
return p->data;
}
return 0;
}

void main()
{
	int n,i,a,l;
	float median;
	sll ll1;
	clrscr();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.add(a);
	}
	l=ll1.len;
	if(l%2==0)
	{
		n=l/2;
		median=(float)(ll1.find(n)+ll1.find(n+1));
		median=(float)median/2;
	}
	else
	{
		n=l/2+1;
		median=(float)ll1.find(n);
	}
	cout<<"median:"<<median;
	getch();
}