/*6. given a single linked list, print the N element from the end of the linked 
list. example 1->2->3->4->5 and 2, output is 4*/


#include<iostream.h>
#include<conio.h>
 
class node
{
public:
  int data;
  node* link;
};

class endll
{
public:
	node *first;
	endll()
	{
	first=NULL;
	}
	void add(int);
	void printNthEle(int);
	void display();
};

void endll::add(int n)
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
 

void endll::printNthEle( int n)
{
    int len = 0, i;
    node *temp = first;
    while (temp != NULL)
    {
	temp = temp->link;
        len++;
    }
 
    if (len < n)
      return;
 
    temp = first;
 
    for (i = 1; i < len-n+1; i++)
       temp = temp->link;
 
    cout<<temp->data;
}

void endll::display()
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
	endll ll1;
	clrscr();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.add(a);
	}
	ll1.display();
	cout<<"Enter Nth element from last to be displayed";
	cin>>n;
	ll1.printNthEle(n);
	getch();
}
