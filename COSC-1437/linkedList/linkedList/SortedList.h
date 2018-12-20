//Nathaniel Clayton
//LinkedList Program
//November 18, 2017
#ifndef SL
#define SL
#include <string>
#include <iostream>
using namespace std;

template <class T>
class SortedList {

public:
	//Function Prototypes
	SortedList();
	SortedList(SortedList &);
	~SortedList();
	void remove(T);
	void insert(T);
	bool find(T);
	void ascending();
	void descending();
	void deleteList();
	void operator=(SortedList &);
	int size();

private:
	//Data
	struct ListNode{
		T value;
		ListNode *next;
	};
	ListNode *head;

	//Function Prototypes
	void deleteNode(T);
	void insertRecursive(ListNode*&, T);
	void copyList(SortedList&);
	int countNodes(ListNode *);
	void displayForward(ListNode*);
	void displayReverse(ListNode*);
	void erase(ListNode*);




};
/*

IMPLEMENTATION  -- PUBLIC MEMBER FUNCTIONS

*/

//Constructor Function
//Pre-Condition: Called Implicitly when object is created
//Post-Condition: head is given null value
template <class T>
SortedList<T>::SortedList() {
	head = nullptr;
}
//Copy Constructor
//Pre-Condition: original object must be passed as argument
//Post-Condition: a copy of the original is created
template<class T>
SortedList<T>::SortedList(SortedList & orig){
	copyList(orig);
}
//Destructor Function
//Pre-Condition: Called when object goes out of scope
//Post-Condition: all dynamically allocated memory is destroyed
template<class T>
SortedList<T>::~SortedList() {
	erase(head);
}
//Public Function to insert a node in a sorted manner
//Pre-Condition: value is passed as an argument
//Post-Condition: node is inserted in array
template<class T>
void SortedList<T>::insert(T s) {
	insertRecursive(head, s);
}
//Function to remove a value from the list
//Pre-Condition: value you want removed is to be passed as argument
//Post-Condition: node containing value is removed from list
template<class T>
void SortedList<T>::remove(T value) {
	deleteNode(value);
}
//Function to delete entire list
//Pre-Condition: List must exist
//Post-Condition: all dynamically allocated memory is destroyed
template<class T>
void SortedList<T>::deleteList(){
	erase(head);
}
//Function to Display The List Values in Ascending Order
//Pre-Condition: ListNode must be given values
//Post-Condition: List contents are displayed to console
template<class T>
void SortedList<T>::ascending(){
	displayForward(head);
}
//Function to Display The List Values in Descending Order
//Pre-Condition: ListNode must be given values
//Post-Condition: List contents are displayed to console
template<class T>
void SortedList<T>::descending(){
	displayReverse(head);
}
//Function to overload assignment operator to copy a List
//Pre-Condition: 
template<class T>
void SortedList<T>::operator=(SortedList & orig) {
	copyList(orig);
}
//Function to Count Number of Items in List
//Pre-Condition: List must exist
//Post-Condition: number of items in list is returned
template<class T>
int SortedList<T>::size() {
	return countNodes(head);
}
//Function to Check List for a given Value
//Pre-Condition: pass the value you a checking as an argument
//Post-Condition: if the value is found in the list, it returns true
template<class T>
bool SortedList<T>::find(T search) {

	ListNode *ptr = head;  // Initialize current
	while (ptr != nullptr) {
		if (ptr->value == search)
			return true;
		ptr = ptr->next;
	}
	return false;
}
/*

IMPLEMENTATION  -- PRIVATE MEMBER FUNCTIONS

*/

//Function to delete entire list
//Pre-Condition: List must exist
//Post-Condition: all dynamically allocated memory is destroyed
template<class T>
void SortedList<T>::erase(ListNode *ptr) {
	if (ptr) {
		ListNode* temp = ptr->next;
		delete ptr;
		erase(temp);
	}
	else
		head = nullptr;
}
//Function to Display The List Values in Ascending Order
//Pre-Condition: ListNode must be given values
//Post-Condition: List contents are displayed to console
template<class T>
void SortedList<T>::displayForward(ListNode* ptr){
	if (ptr) {
		cout << ptr->value << endl;
		displayForward(ptr->next);
	}
}
//Function to Display The List Values in Descending Order
//Pre-Condition: ListNode must be given values
//Post-Condition: List contents are displayed to console
template<class T>
void SortedList<T>::displayReverse(ListNode *ptr){
	if (ptr) {
		displayReverse(ptr->next);
		cout << ptr->value << endl;
	}
}
//Function to make a copy of a SortedList object
//Pre-Condition: must pass sorted list object to be copied as argument
//Post-Condition: a copy of the SortedList is created 
template<class T>
void SortedList<T>::copyList(SortedList & list){

	if (list.head == nullptr)
		head = nullptr;
	else {
		ListNode *ptr1, *ptr2;

		head = new ListNode;
		head->value = list.head->value;
		ptr1 = list.head->next;
		ptr2 = head;

		while (ptr1) {
			ptr2->next = new ListNode;
			ptr2 = ptr2->next;
			ptr2->value = ptr1->value;
			ptr1 = ptr1->next;			
		}
		ptr2->next = nullptr;
	}

}
//Function to delete a value found in the List
//Pre-Condition: send value you want deleted as argument
//Post-Condition: Node containing the search value will be deleted
template<class T>
void SortedList<T>::deleteNode(T search) {
	ListNode *nodePtr, *previousPtr;

	if (!head || !find(search)) {
		cout << "Sorry, unable to find " << search << " in the list." << endl;
		return;
	}

	if (head->value == search) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else {
		nodePtr = head;
		previousPtr = nullptr;

		while (nodePtr->value != search) {
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr) {
			previousPtr->next = nodePtr->next;
			delete nodePtr;
			cout << search << " has been removed from the list." << endl;
		}
	}

}
//Function to recursively add a node in sorted format
//Pre-Condition: ListNode object must be created
//Post-Condition: new node is inserted 
template<class T>
void SortedList<T>::insertRecursive(ListNode *& ptr, T s){

	if (!ptr || s < ptr->value) {
		ListNode * temp;
		temp = ptr;
		ptr = new ListNode;
		ptr->value = s;
		ptr->next = temp;
	}
	else
		insertRecursive(ptr->next, s);

}
//Function to Count Number of Items in List
//Pre-Condition: List must exist
//Post-Condition: number of items in list is returned
template<class T>
int SortedList<T>::countNodes(ListNode * ptr){
	if (ptr)
		return 1 + countNodes(ptr->next);
	else
		return 0;
}
#endif
