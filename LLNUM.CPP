/*1. given a number create a single linked list where each node has one digit in it. your code need to have linked list created (not print 1->2->3 on the console). for example if I give 1234 as input in the memory linked list should be created  with a node 1 pointing to node 2 pointing to node 3 pointing to node4*/
#include<iostream.h>
#include<conio.h>
class node
{
	public:
		int data;
		node *link;
};

class numll
{
	public:
		node *first;
		numll()
		{
			first=NULL;
		}
		void create(int);
		void display();
};

void numll::create(int n)
{
	int r;
	while(n!=0)
	{
		r=n%10;
		node *temp=new node;
		temp->data=r;
		temp->link=first;
		first=temp;
		n=n/10;
	}
}

void numll::display()
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
	int n;
	numll ll1;
	clrscr();
	cout<<"Enter a Number:" ;
	cin>>n;
	ll1.create(n);
	ll1.display();
	getch();
}