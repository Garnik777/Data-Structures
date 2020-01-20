#include <iostream>

struct Node
{
	Node *prev;
	int data;
	Node *next;
}*first = nullptr;

int create(int A[], int n)
{
	Node *t, *last;
	int i;
	first = new Node;
	first->data  = A[0];
	first->prev = first->next =nullptr;
	last = first;

	for ( i = 1; i < n; i++)
	{

		t = new Node;
		t-> data = A[i];
		t-> next = last->next;
		t-> prev = last;
		last -> next = t;
		last = t;
	}
}

int length(Node *p)
{	
	int len = 0;
	while ( p != nullptr)
	{
		len++;
		p = p-> next;
	}
	return len;
}


void insert(Node *p, int index, int x)
{
	Node *t;
	if (index < 0 || index > length(p)) {

		return;
	}
	if (index == 0)
       	{
		t = new Node;
		t-> data = x;
		t-> prev = nullptr;
		t-> next = first;
		first->prev = t;
		first = t;

	}else{
		for (int i =1; i < index -1; i++) {
			p = p->next;
		}
		
			t = new Node;
			t-> data= x;
			t->next = p->next;
			t->prev = p;
			if (p->next) {
				p->next->prev = t;
			}
			p->next = t;
		

	}
}

int delete_node(Node *p, int index )
{
	int x = -1;
	if (index < 0 || index > length(p)) {
		return -1;
	}

	if (index == 1)
       	{

		first = first->next;
		x = p->data;
		if(first) {
			first->prev = nullptr;
		}
		delete p;
	}else{
		for (int i = 0; i < index-1; i++)
		{
			p = p->next;
		}
		p->prev->next = p->next;
		if (p->next) {
			p->next->prev  = p->prev;
			x = p->data;
			delete p;
		}
		return x;
	}
}

void reverse(Node *p)
{
	Node *temp;
	while( p != nullptr)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if (p != nullptr && p->next == nullptr)
		{
			 first = p;
		}
	}
}

void display(Node *p)
{
	while(p != nullptr)
	{
		std::cout << p->data;
		p = p->next;

	}
}

int main()
{
	Node *a = nullptr;
	int size = 0;
	int *A = new int [size];
	int ch;
	int x = 0,index = 0;
	std::cout << "Enter  size of linked_list";
	std::cin >> size;
	create(A,size);
	do {

		std::cout << "\n\nMenu\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Display\n";

		std::cout << "enter your choice";
		std::cin >> ch;
		switch(ch)
		{
			case 1: std::cout << " Enter an element: ";
				std::cin >> index >> x;
				insert(first,index,x);
				break;
			case 2: std::cout << "Enter index: ";
				std::cin >> index;
				x = delete_node(a, index);
				std::cout << "deleted element is: " << x;
				break;
			case 3: display(first);
		}

	}while(ch < 6);
	return 0;
}

