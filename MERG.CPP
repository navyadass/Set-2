/*10. given two sorted linked lists, merge them into single sorted linked list 
using same nodes of bboth the lists.*/

#include<iostream.h>
#include<conio.h>
class node
{
public:
	int data;
	node *next;
};
class ll
{
public:
	node *first;
	ll()
	{
	first=NULL;
	}
	void add(int);
	void display();
	void merg(ll &a,ll &b);
};

void ll::add(int n)
{
	node *p;
	node *temp=new node;
	if(first==NULL)
	{
		temp->data=n;
		temp->next=NULL;
		first=temp;
	}
	else
	{
		for(p=first;p->next!=NULL;)
			p=p->next;
		temp->data=n;
		p->next=temp;
		temp->next=NULL;
	}
}

void ll::display()
{
	node *t=first;
	while(t!=NULL)
	{
		cout<<t->data;
		if(t->next!=NULL)
		cout<<"->";
		t=t->next;
	}
}

void ll::merg(ll &a,ll &b)
{
	first=NULL;
	node *p=first;
	if(a.first==NULL&&b.first==NULL)
		return;
	if(a.first->data<b.first->data)
	{
		first=a.first;
		a.first=a.first->next;
	}
	else
	{
		first=b.first;
		b.first=b.first->next;
	}
	p=first;
	while(a.first!=NULL&&b.first!=NULL)
	{
		if(a.first->data<b.first->data)
		{
			p->next=a.first;
			p=a.first;
			a.first=a.first->next;
		}
		else
		{
			p->next=b.first;
			p=b.first;
			b.first=b.first->next;
		}
	}
	while(a.first!=NULL)
	{
		p->next=a.first;
		p=a.first;
		a.first=a.first->next;
	}
	while(b.first!=NULL)
	{
		p->next=b.first;
		p=b.first;
		b.first=b.first->next;
	}
	p->next=NULL;
}
void main()
{
	int n,i,a;
	ll ll1,ll2,ll3;
	clrscr();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.add(a);
	}
	ll1.display();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll2.add(a);
	}
	ll2.display();
	ll3.merg(ll1,ll2);
	ll3.display();
	getch();
}
