#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <string>
#include <list>
#include "simplelist.hpp"
/* 
Derived class from SimpleList
A queue is defined by pushing to the black of the linked list, and removing from the
front of the linked list (FIFO).
The Stack and Queue have the same name functions for easier use in the main function
*/
template <typename type>
class Queue: public SimpleList<type> {
	public:
		Queue(string name):SimpleList<type>(name) {} //constructor
		//Push into Queue (also known as Enqueuing)
		void push(type value) {
			SimpleList<type>::insert_end(value);
		}
		//Pop from Queue (also known as Dequeuing)
		type pop() {
			return SimpleList<type>::remove_front();
		}
};

#endif
		
		