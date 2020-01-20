#include <iostream>

class Node
{
public:	
	int data;
	Node* next;
};

class linked_list
{
private:
	Node *first;
public:
	linked_list() { first = nullptr;}
	linked_list(int A[], int n);
	~linked_list();
	void display();
	void insert(int index, int x);
	int delete_node(int index);
	Node* lsearch(int key);
	int count();
};

linked_list::linked_list(int A[], int n)
{
	Node *last, *t;
	int i = 0;
	first = new Node;
	first->data = A[0];
	first->next = nullptr;
	last = first;

	for (i = 1; i < n; i++) {
		t = new Node;
		t->data = A[i];
		t->next = nullptr;
		last->next = t;
		last = t;
	}
}

linked_list::~linked_list()
{
	Node *p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}



void linked_list::display()
{
	Node *p = first;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
		
	}
	std::cout << std::endl;	
}


int linked_list::count()
{
	Node *p = first;
	int c = 0;
	while (p != nullptr)
	{
		c++;
		p = p->next;
	}
	return c;
}





Node* linked_list::lsearch( int key)
{	
	Node *p = first;
	Node *q = nullptr;

	while (p != nullptr)
	{
		if( key == p->data)
	       	{
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}
			q = p;
			p = p->next;
	}
	return nullptr;
}

void linked_list::insert(int index, int x)
{
	Node *p = first;
	Node *t;
	int i;
	if(index < 0 || index > count()) {
		return ;
	}
	t = new Node;
	t-> data = x;
	t-> next = nullptr;
	if (index == 0) {

		t->next = first;
		first = t;
	}
	else {
		for (i = 0; i < index-1; i++) {
			p = p->next;
			t->next = p->next;
			p->next = t;
		}
	}
}



Node* rsearch(Node* p, int key)
{
	if( p == nullptr){
		return nullptr;	
	}
	else if(key == p->data){
		return p;
	}
	else{
		return rsearch(p->next,key); 
	}	
}

int linked_list::delete_node( int index)
{
	Node *p, *q = nullptr;
	int x = -1;
	if( index < 1 || index > count()) {
		return -1;
	}
	if(index == 1)
       	{
		p = first;
		first = first->next;
		x = p-> data;
		delete p;
	}
	else {
		p = first;
		for(int i = 0; i < index-1; i++) {
			q = p;
			p = p->next;

		}
		q-> next = p->next;
		x = p->data;
		delete p;
	}
	return x;	
}


int main()
{
	int ch;
	int index;
	int x = 0;
	int size = 0;
	int* A = new int [size];
	linked_list l(A,size);
	std::cout << "Enter  size of linked_list";
	std::cin >> size;
	do {

		std::cout << "\n\nMenu\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Search\n";
		std::cout << "4. Display\n";

		std::cout << "enter your choice";
		std::cin >> ch;
		switch(ch)
		{
			case 1: std::cout << " Enter an element: ";
				std::cin >> index >> x;
				l.insert(index,x);
				break;
			case 2: std::cout << "Enter index: ";
				std::cin >> index;
				x = l.delete_node( index);
				std::cout << "deleted element is: " << x;
				break;
			case 3: std::cout << "Enter element to search: ";
				std::cin >> x;
				l.lsearch(x);
				std::cout << "Element " << x; 
				break;
			case 4: l.display();
		}
	}while(ch < 5 );
	return 0;
		
}	
