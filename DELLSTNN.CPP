/*7. given a single linked list and value N, delete the last N nodes of the linked 
list. for example 1->2->3->4 and 2, output should be 1->2->NULL*/


#include<iostream.h>
#include<conio.h>
 
class node
{
  public:
	int data;
  node* link;
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
	void delNnode(int);
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
 

void ll::delNnode( int n)
{
    int len = 0, i;
    node *p,*temp = first;
    while (temp != NULL)
    {
	temp = temp->link;
	len++;
    }

    if (len < n)
      return;

    temp = first;

    for (i = 1; i < len-n+1; i++)
    {
       p=temp;
       temp = temp->link;
    }
    p->link=NULL;
    while(temp!=NULL)
    { p=temp;
    temp=temp->link;
    delete p;
    }


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
	cout<<"Enter nth node from where nodes hav to be deleted:";
	cin>>n;
	ll1.delNnode(n);
	ll1.display();
	getch();
}
