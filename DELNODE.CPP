/*5. given a single(not sorted) linked list, and a value, delete the value from 
the linked list. the value may exist or may not exist in the list*/


#include<iostream.h>
#include<conio.h>

class node
{
	public:
	int data;
	node *link;
};

class ll
{
     public:	node *first;
	ll()
	{
		first=NULL;
	}
	void add(int);
	void del(int);
	void display();
};

void ll::add(int n)
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

void ll::del(int n)
{
	node *p=first,*t;
	while(p!=NULL&&p->data!=n)
	{
		t=p;
		p=p->link;
	}
	if(p)
	{
		t->link=p->link;
		delete p;
	}
	else
		cout<<"node not present";
}

void ll::display()
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

void main()
{
	int n,i,a;
	ll ll1;
	clrscr();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.add(a);
	}
	ll1.display();
	cout<<"\nEnter the number u want to delete:\n";
	cin>>n;
	ll1.del(n);
	ll1.display();
	getch();

}