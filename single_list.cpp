#include <iostream>

class Node
{
public:	
	int data;
	Node* next;
};

class single_list
{
private:
	Node *first;
public:
	single_list() { first = nullptr;}
	single_list(int A[], int n);
	~single_list();
	void display();
	void insert(int index, int x);
	int delete_node(int index);
	Node* search(int key);
	int count();
};

single_list::single_list(int A[], int n)
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

single_list::~single_list()
{
	Node *p = first;
	while (first)
	{
		first = first->next;
		delete p;
		p = first;
	}
}



void single_list::display()
{
	Node *p = first;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
		
	}
	std::cout << std::endl;	
}


int single_list::count()
{
	Node *p = first;
	int c = 0;
	while (p)
	{
		c++;
		p = p->next;
	}
	return c;
}


Node* single_list::search( int key)
{	
	Node *p = first;
	Node *q = nullptr;

	while (p != nullptr)
	{
		if( key == p->data)
	       	{
			return p;
		}
		p = p->next;
	}
	return nullptr;
}

void single_list::insert(int index, int x)
{
	Node *t, *p = first;
	
	if(index < 0 || index > count()) {
		return;
	}
	t = new Node;
	t-> data = x;
	t-> next = nullptr;
	if (index == 0) {

		t->next = first;
		first = t;
	}
	else {
		for (int i = 0; i < index-1; i++) {
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

int single_list::delete_node( int index)
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
		x = p->data;
		delete p;
		return x;
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
	Node *temp;
	int x;
	int index;
	int ch;
	int A[] = {1,2,3,4,5};
	single_list l(A,5);

	do {

		std::cout << "\n\nMenu\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Search\n";
		std::cout << "4. Display\n";

		std::cout << "enter your choice: ";
		std::cin >> ch;
		switch(ch)
		{
			case 1: std::cout << " Enter index at which element to be inserted: ";
				std::cin >> index;
				std::cout << "Enter element to be inserted: ";
			       	std::cin >> x;
				l.insert(index,x);
				break;
			case 2: std::cout << "Enter index at which element to delete: ";
				std::cin >> index;
				std::cout << "Deleted element  "<< l.delete_node( index);
				break;
			case 3: std::cout << "Enter element to search: ";
				std::cin >> x;
				temp = l.search(x);
				if (temp != nullptr) {
					std::cout << "Element is found " << x;
				}else{
					std::cout << "Element is not found\n";
				}	
				break;
			case 4: l.display();
		}
	}while(ch < 5 );
	return 0;
		
}	
