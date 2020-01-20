#include <iostream>

class Node
{
	public:
	Node *lchild;
	int data;
	Node *rchild;
}*root = NULL;

Node* insert(int key)
{
	Node *t = root;
	Node *r = NULL, *p;
	if (root == NULL) {
		p = new Node;
		p -> data = key;
		p-> lchild = p-> rchild = NULL;
		root = p;
		return p;
	}

	while ( t != NULL)
       	{
		r = t;
		if (key < t -> data) {
			t = t->lchild;
		}else if(key > t->data) {
			t = t->rchild;
		}else{
			return t;
		}
	}

	p = new Node;
	p -> data = key;
	p ->lchild = p-> rchild = NULL;
	if ( key < r-> data) {
		r->lchild = p;
	        	
	}else{
		r->rchild = p; 
	}
			
}


void inorder(Node* p)
{
	if(p)
       	{
		inorder(p->lchild);
		std::cout << p->data<< " ";
		inorder(p-> rchild );
	}

}	

Node* search(int key)
{
	Node *t = root;
	while (t != nullptr)
	{
		if (key == t->data)
		{
			return t;
		}else if (key < t->data)
		{
			t = t->lchild;
		}else{
			t = t->rchild;
		}
	}
	return nullptr;
}

Node *r_insert(Node *p, int key)
{
	Node *t = nullptr;
	if (p == nullptr)
	{
		t = new Node;
		t->data = key;
		t->lchild = t->rchild = nullptr;
		return t;
	}
	if (key < p->data)
	{
		p->lchild = r_insert(p->lchild,key);
	}else if(key > p->data)
	{
		p->rchild = r_insert(p->rchild,key);
	}
	return p;
}

int height(Node *p)
{
	int x,y;
	if (p == nullptr) return 0;
	x = height(p->lchild);
	y = height(p->rchild);
	return x > y? x +1:y +1;
}

Node *in_pre(Node *p)
{
	while (p && p->rchild != nullptr)
	{
		p = p->rchild;
	}
	return p;
}

Node *in_succ(Node *p)
{
	while (p && p->lchild != nullptr)
	{
		p = p->lchild;
	}
	return p;
}

Node* delete_node(Node *p, int key)
{
	Node *q;
	if (p == nullptr) {
		return nullptr;	
	}
	if (p->lchild == nullptr && p->rchild == nullptr)
	{
		if (p == root)
		{
			root = nullptr;
		}
		delete p;
		return nullptr;
	}
	
	if (key < p->data) {
		p->lchild = delete_node(p->lchild, key);
	}else if(key > p->data) {
		p->rchild = delete_node(p->rchild,key);
	}else{
		if (height(p->lchild) > height(p->rchild))
		{
			q = in_pre(p->lchild);
			p->data = q->data;
			p->lchild = delete_node(p->lchild,q->data);	
		}
		else{
			q = in_succ(p->rchild);
			p->data = q->data;
			p->rchild = delete_node(p->rchild,q->data);

		}
	}
	return p;
}

int main()
{
	Node *temp;
	root = insert( 0);
	int ch;
        int x = 0;
               do {

                std::cout << "\n\nMenu\n";
                std::cout << "1. Insert\n";
                std::cout << "2. Delete\n";
                std::cout << "3. Search\n";
                std::cout << "4. Display\n";

                std::cout << "Please enter number from 1 - 4: ";
                std::cin >> ch;
                switch(ch)
                {
                        case 1: std::cout << " Enter an element: ";
                                std::cin >> x;
                                r_insert(root,x);
                                break;
                        case 2: std::cout << "Which element you want to delete: ";
                                std::cin >> x;
                                temp = delete_node(root,x);
                                std::cout << "deleted element is: " << temp->data;
                                break;
                        case 3: std::cout << "Enter element to search: ";
                                std::cin >> x;
                                search(x);
                                std::cout << "Element is found " << x;
				break;
			case 4: inorder(root); 
	
		}
	}while(ch < 5);
	return 0;
}	
