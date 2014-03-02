/*2. given a single linked list, write a program to reverse the single linked list.
for example 1->2->3 should be converted to 3->2->1. 
please write this program using recursion, without recursion*/

#include<iostream.h>
#include<conio.h>
class node
{
public:
	int data;
	node *link;
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
	void rev_rec(node **);
	void display();
};

void revll::add(int n)
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

void revll::rev_rec(node** head_ref)
{
     node* first;
     node* rest;
      
    /* empty list */
    if (*head_ref == NULL)
       return;   
 
    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;  
    rest  = first->link;
 
    /* List has only one node */
    if (rest == NULL)
       return;   
 
    /* reverse the rest list and put the first element at the end */
    rev_rec(&rest);
    first->link->link  = first;  
     
    /* tricky step -- see the diagram */
    first->link  = NULL;          
 
    /* fix the head pointer */
    *head_ref = rest;              
}

void revll::display()
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
	ll1.rev_rec(&ll1.first);
	ll1.display();
	getch();
}
