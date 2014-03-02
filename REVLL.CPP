/*2. given a single linked list, write a program to reverse the single linked list. for example 1->2->3 should be converted to 3->2->1. please write this program using recursion, without recursion*/

#include<iostream.h>
#include<conio.h>
class node
{
public:
	int data;
	node *next;
};
class revll
{
public:
	node *first;
	revll()
	{
	first=NULL;
	}
	void add(int);
	void rev();
	void display();
};

void revll::add(int n)
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

void revll::rev()
{
	node *p, *q, *r;
	if(first == NULL)
	{
		return;
	}
	p = first;
	q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	first= p;
}

void revll::display()
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

void main()
{
	int n,i,a;
	revll ll1;
	clrscr();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.add(a);
	}
	ll1.display();
	cout<<"\nAfter reversing linked list\n";
	ll1.rev();
	ll1.display();
	getch();
}
