#ifndef SIMPLELIST_H
#define SIMPLELIST_H

#include <stdlib.h>
#include <string>
#include <list>

using namespace std;
//SimpleList template class definition
template <typename type>
class SimpleList {
	private:
		//Node structure definition
		struct Node {
			type data;
			Node* next;
			Node(type D, Node* N) : data(D), next(N){}
		};
		Node* head;
		Node* end;
		//Initialize variables
		int size = 0; 
		string listname = 0;
	
	public:
		SimpleList(string name) : head(0), end(0), size(0), listname(name) {}; //constructor
		bool listIsEmpty() { return (size == 0); } //Check if list is empty
		string getName() { return listname; }  //Gets the name of the list
		//virtual functions for push and pop to be defined in derived classes
		virtual void push(type value) = 0 ; 
		virtual type pop() = 0;
	
	protected:
		void insert_front(type value);
		void insert_end(type value);
		type remove_front();
		
};	

//Insertion to the front of the linked list
template <typename type>
void SimpleList<type>::insert_front(type value) {	
	if (listIsEmpty()) {	
		Node *temp = new Node(value,head);
		head = temp;
		end = temp;
		size++;
	}
	else {
		Node *temp = new Node(value,head);
		temp->data = value;
		temp->next = head;
		head = temp;		
		size++;
	}
}

//Insertion to the end of the linked list
template <typename type>
void SimpleList<type>::insert_end(type value) {
	
	if(listIsEmpty()) {
		Node *temp = new Node(value, NULL);	
		head = temp;
		end = temp;		
		size++;
	}
	else {
		Node *temp = new Node(value, NULL);	
		temp->data = value;
		temp->next = NULL;
		end->next = temp;
		end = temp;		
		size++;
	}
}

//Deletion and Extraction from the front of the linked list
template <typename type>
type SimpleList<type>::remove_front() {
		Node *temp = head;
		type value = head->data;
		head = temp->next;	
		size--;
		return value;
}
#endif
		
	
	
	
	
	
	
	
	