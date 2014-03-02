/*3. given a single, sorted linked list convert that into a single, sorted, 
circular linked list. for example 1->2->3->NULL should be 1->2->3->1*/

#include<iostream.h>
#include<conio.h>
class node
{
public:
	int data;
	node *link;
};
class cll
{
public:
	node *first;
	cll()
	{
	first=NULL;
	}
	void add(int);
	void convert();
	void display();
	void dispcll();
};

void cll::add(int n)
{
	node *p;
	node *temp=new node;
	if(first==NULL)
	{
		temp->data=n;
		temp->link=NULL;
		first=temp;
	}
	else
	{
		for(p=first;p->link!=NULL;)
			p=p->link;
		temp->data=n;
		p->link=temp;
		temp->link=NULL;
	}
}

void cll::convert()
{
	node *q=first;
	while (q != NULL)
	{
		q=q->link;
	}

	q->link=first;
}

void cll::display()
{
	node *t=first;
	while(t!=NULL)
	{
		cout<<t->data;
		if(t->link!=NULL)
		cout<<"->";
		t=t->link;
	}
}

void cll::dispcll()
{
	node *t=first;
	while(t!=first)
	{
		cout<<t->data;
		if(t->link!=first)
			cout<<"->";
		t=t->link;
	}
	cout<<"->"<<t->data;
}
void main()
{
	int n,i,a;
	cll ll1;
	clrscr();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.add(a);
	}
	ll1.display();
	ll1.convert();
	ll1.dispcll();
	getch();
}
