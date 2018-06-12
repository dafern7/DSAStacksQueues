#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <string>
#include <list>
#include "simplelist.hpp"

/* 
Derived class from SimpleList
A stack is defined by pushing to the front of the linked list, and removing from the
front of the linked list (LIFO).
The Stack and Queue have the same name functions for easier use in the main function
*/

template <typename type>
class Stack: public SimpleList<type>{
	public:
		Stack(string name):SimpleList<type>(name) {} //constructor
		//Push onto stack 
		void push(type value) { 
			SimpleList<type>::insert_front(value);
		}
		//Pop off the stack
		type pop() {
			return SimpleList<type>::remove_front();
		}
};

#endif
	
			
		