/*4. given a single, sorted, circular linked list and a value, insert the value 
as a new node at the appropriate location (to keep the linked list sorted). 
example 1->2->4->1 and value 3 output shoudl be 1->2->3->4->1*/


#include<iostream.h>
#include<conio.h>

class node
{
public:
	int data;
	node *next;
};

class sortcll
{   public:
	node *first;
	sortcll()
	{
	first=NULL;
	}
	void insert(int);
	void display();
};

void sortcll::insert(int n)
{
   node* current = first;
  node *temp=new node;
   temp->data=n;
  // Case 1 of the above algo
  if (current == NULL)
  {
     temp->next = temp;
     first=temp;
  }
 
  // Case 2 of the above algo
  else if (current->data >= n)
  {
    /* If value is smaller than head's value then
      we need to change next of last node */
    while(current->next != first)
	current = current->next;
    current->next = temp;
    temp->next = first;
    first = temp;
  }
 
  // Case 3 of the above algo
  else
  {
    /* Locate the node before the point of insertion */
    while (current->next!= first && current->next->data < n)
      current = current->next;
 
    temp->next = current->next;
    current->next = temp;
  }
}



void sortcll::display()
{
  node *t=first;
	do
	{
		cout<<t->data;
		if(t->next!=first)
			cout<<"->";
		t=t->next;
	}while(t!=first);
}

void main()
{
	int n,i,a;
	sortcll ll1;
	clrscr();
	cout<<"Enter a Number of nodes to add:" ;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		ll1.insert(a);
	}
	ll1.display();
	getch();
}