#ifndef parsing_h
#define parsing_h

#include <stdlib.h>
#include <string>
#include <list>
#include "simplelist.hpp"
/*
This function returns whether or not the given list name was repeated in the list of list names
*/
template <typename type>
bool repeated_name( list<SimpleList<type>*> list_number,  string list_name) {
	bool isRepeated = false;
	typename list<SimpleList<type>*>::const_iterator i;
	for (i = list_number.begin(); i != list_number.end(); ++i) {
		if ((*i)->getName() == list_name) {
			isRepeated = true;
			return isRepeated;
		}
		else {
			return false;
		}
	}
}

/*
This function returns the pointer to the list name if found, and returns null if the list name is not found in the list of lists.
*/
template <typename type>
SimpleList<type>* find_name( list<SimpleList<type>*> list_number,  string list_name) {
	typename list<SimpleList<type>*>::const_iterator i;
	for (i = list_number.begin(); i != list_number.end(); ++i) {
		if ((*i)->getName() == list_name) {
			return (*i);
		}
	}
	return NULL;
}
#endif
