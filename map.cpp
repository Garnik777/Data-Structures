#include <iostream> 
#include <iterator> 
#include <map> 

using namespace std; 
int main() 
{ 

	// empty map container 
	map<int, int> m; 

	// insert elements in random order 
	m.insert(pair<int, int>(1, 40)); 
	m.insert(pair<int, int>(2, 30)); 
	m.insert(pair<int, int>(3, 60)); 
	m.insert(pair<int, int>(4, 20)); 
	m.insert(pair<int, int>(5, 50)); 
	m.insert(pair<int, int>(6, 50)); 
	m.insert(pair<int, int>(7, 10)); 
	// printing map m 
	map<int, int>::iterator itr; 
	cout << "\nThe map m is : \n"; 
	cout << "\tKEY\tELEMENT\n"; 
	for (itr = m.begin(); itr != m.end(); ++itr) { 
		cout << '\t' << itr->first 
			<< '\t' << itr->second << '\n'; 
	} 
	cout << endl; 

	// assigning the elements from m to m2 
	map<int, int> m2(m.begin(), m.end()); 

	// print all elements of the map m2 
	cout << "\nThe map m2 after"
		<< " assign from m is : \n"; 
	cout << "\tKEY\tELEMENT\n"; 
	for (itr = m2.begin(); itr != m2.end(); ++itr) { 
		cout << '\t' << itr->first 
			<< '\t' << itr->second << '\n'; 
	} 
	cout << endl; 
	// remove all elements up to 
	// element with key=3 in m2 
	cout << "\nm2 after removal of"
			" elements less than key=3 : \n"; 
	cout << "\tKEY\tELEMENT\n"; 
	m2.erase(m2.begin(), m2.find(3)); 
	for (itr = m2.begin(); itr != m2.end(); ++itr) { 
		cout << '\t' << itr->first 
			<< '\t' << itr->second << '\n'; 
	} 
	// remove all elements with key = 4 
	int num; 
	num = m2.erase(4); 
	cout << "\nm2.erase(4) : "; 
	cout << num << " removed \n"; 
	cout << "\tKEY\tELEMENT\n"; 
	for (itr = m2.begin(); itr != m2.end(); ++itr) { 
		cout << '\t' << itr->first 
			<< '\t' << itr->second << '\n'; 
	} 

	return 0; 
} 

