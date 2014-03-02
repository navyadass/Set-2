/*8. given a double linked list with head and tail pointers, find the middle 
element of the linked list*/


#include<iostream.h>
#include<conio.h>
class node
{
public:
	int data;
	node *rlink,*llink;
};

class dll
{    public:
	node *first,*last;
	dll()
	{
		first=NULL;
		last=NULL;
	}
	void insert(int x);
	void display();
	void midleele();
};

void dll::insert(int x)
{
	node *temp=new node;
	temp->data=x;
	if(first==NULL)
	{
		temp->llink=NULL;
		temp->rlink=NULL;
		first=temp;
		last=temp;
	}
	else
	{
		last->rlink=temp;
		temp->llink=last;
		temp->rlink=NULL;
		last=temp;
	}
}

void dll::display()
{
	node *p;
	for(p=first;p!=NULL;p=p->rlink)
	{
		cout<<p->data;
		if(p->rlink!=NULL)
			cout<<"->";
	}
}

void dll::midleele()
{
	node *l,*r;
	r=first;
	l=last;
	while(l->llink!=r->rlink)
	{
		l=l->llink;
		r=r->rlink;
	}
	cout<<r->rlink->data;
}

void main()
{
	int n,i,a;
	dll ll1;
	clrscr();
	cout<<"Enter no of nodes:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.insert(a);
	}
	ll1.display();
	ll1.midleele();
	getch();
}