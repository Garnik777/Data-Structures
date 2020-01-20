#include <iostream>

class Vector {
private:
        int * arr;
        int _size;
        int _capacity;

public:
        Vector(int size = 1, int default_value = 0)
        {
                _size = size;
                _capacity = size;
                arr = new int[_size];
                for (int i = 0; i < _size; i++)
                        arr[i] = default_value;
        }

        int& operator [] (int index) {
                return arr[index];
        }

        void push_back(int element);
        void pop_back();
        int search(int key);
        void display();
        int size() { return _size;}
};

int swap(int *x, int *y)
{
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
}

int Vector::search(int key)
{
        for (int i = 0; i < size(); i++)
        {
		if(key == arr[i])
                {
                        swap(&arr[i],&arr[0]);
                        return i;
                }
        }
        return -1;
}

void Vector::display()
{
        std::cout << "\nElements are\n";
        for (int i = 0; i < size();i++)
        {
                std::cout << arr[i] << " ";
        }
}

void Vector::push_back(int element)
{
        if (_size == _capacity) {
                int * tmp = new int[2 * _capacity];
                for (int i = 0; i < _capacity; i++)
                        tmp[i] = arr[i];
                delete[] arr;
                arr = tmp;
                _capacity *= 2;
        }
        arr[_size] = element;
        _size++;
}

void Vector::pop_back()
{
        _size--;
        if (_size < _capacity / 4) {
                int * tmp = new int[_capacity / 2];
                for (int i = 0; i < _size; i++)
                        tmp[i] = arr[i];
                delete[] arr;
                arr = tmp;
                _capacity /= 2;
        }
}

int main()
{
        Vector v;
        int a;
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
                                v.push_back(x);
                                break;
                        case 2: std::cout << "Which element you want to delete: ";
                                std::cin >> x;
                                v.pop_back();
                                std::cout << "deleted element is: " << x;
                                break;
                        case 3: std::cout << "Enter element to search: ";
                                std::cin >> x;
                                a = v.search(x);
                                std::cout << "Element index is " << a;
                                break;
                        case 4: v.display();

                }
        }while(ch < 5);

}
