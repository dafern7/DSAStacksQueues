#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "simplelist.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "parsing.hpp"

using namespace std;


int main() {
	//input/output file definitions
	ifstream input;
	ofstream output;
	//Input file, open it
	string input_file;
	cout << "Enter name of input file:";
	cin >> input_file;
	input.open(input_file.c_str());
	//Output file initialization
	string output_file;
	cout << "Enter name of output file:";
	cin >> output_file;
	output.open(output_file.c_str());
	//List of stacks and queues declarations
	list<SimpleList<int>*> intSimpleList;
	list<SimpleList<double>*> doubleSimpleList;
	list<SimpleList<string>*> stringSimpleList;
	
	/*
	This main function reads the open input file until the end of file.
	While reading, it separates each word based on whitespace and performs functions
	based on the word.
	*/
	while(!input.eof()) {		
		// The first word of every command is either 'create','push', or 'pop'
		string first_word;
		// >> operator is used to extract the first string in the input file
		input >> first_word;
		// This if statement corresponds to the creation of a stack or a queue.
		if (first_word == "create") {
			// The next word always designates the type and the name of the stack/queue being created,
			// pushed or popped
			// Use the get function from the iostream library to get the first character of the second word
			input.get();
			char second_word_first_char;
			second_word_first_char = input.get(); //store the first letter of the second word into a char
			// Now take out the rest of the second word using the >> operator 
			string cut_second_word;
			input >> cut_second_word;
			 // Store the full second word as the name of the object to be created (stack/queue)
			string second_word = second_word_first_char + cut_second_word;
			//The third word (only available if the first command is 'create' or 'push') designates the object to be pushed or created.
			string third_word;
			input >> third_word;
			output << "PROCESSING COMMAND: " << first_word << " " << second_word << " " << third_word << endl;
			if (second_word_first_char == 'i') {	
				//Check if the name of the stack/queue already exists in the list of stacks/queues
				if (repeated_name(intSimpleList, second_word) == true) {
					output << "ERROR: This name already exists!" << endl;
					}
				else {
					//Creating the new stack/queue and adding it to the list of stacks/queues
					if (third_word == "stack") {
						SimpleList<int> *SLint;
						SLint = new Stack<int>(second_word);
						intSimpleList.push_back(SLint);
						}
					else {
						SimpleList<int> *SLint;
						SLint = new Queue<int>(second_word);
						intSimpleList.push_back(SLint);
					}
				}
			}
			else if (second_word_first_char == 'd') {	
				if (repeated_name(doubleSimpleList, second_word) == true) {
					output << "ERROR: This name already exists!" << endl;
					}
				else {
					if (third_word == "stack") {
						SimpleList<double> *SLdouble;
						SLdouble = new Stack<double>(second_word);
						doubleSimpleList.push_back(SLdouble);
						}
					else {
						SimpleList<double> *SLdouble;
						SLdouble = new Queue<double>(second_word);
						doubleSimpleList.push_back(SLdouble);
					}
				}
			}
			else if (second_word_first_char == 's') {	
				if (repeated_name(stringSimpleList, second_word) == true) {
					output << "ERROR: This name already exists!" << endl;
					}
				else {
					if (third_word == "stack") {
						SimpleList<string> *SLstr;
						SLstr = new Stack<string>(second_word);
						stringSimpleList.push_back(SLstr);
						}
					else {
						SimpleList<string> *SLstr;
						SLstr = new Queue<string>(second_word);
						stringSimpleList.push_back(SLstr);
					}
				}
			}
			//These else statements track locations at which unforeseen errors occur.
			else { output << "Error at CREATE" << endl; }
			}
		// This if statement corresponds to a push into a stack or queue
		else if (first_word == "push") { 
			input.get();
			char second_word_first_char;
			second_word_first_char = input.get(); 
			string cut_second_word;
			input >> cut_second_word;
			string second_word = second_word_first_char + cut_second_word; 
			if (second_word_first_char == 'i') {
				int third_word;
				input >> third_word;
				output << "PROCESSING COMMAND: " << first_word << " " << second_word << " " << third_word << endl;
				SimpleList<int> *n = find_name(intSimpleList, second_word);
				if (n == NULL) {
					output << "ERROR: This name does not exist!" << endl;
				}
				else {
					//Having push be the same function name in Stack and Queue saves another if statement in this section
					n->push(third_word); 
				}
			}
			
			else if (second_word_first_char == 'd') {
				double third_word;
				input >> third_word;
				output << "PROCESSING COMMAND: " << first_word << " " << second_word << " " << third_word << endl;
				SimpleList<double> *n = find_name(doubleSimpleList, second_word);
				if (n == NULL) {
					output << "ERROR: This name does not exist!" << endl;
				}
				else {
					n->push(third_word);
				}
			}
			
			else if (second_word_first_char == 's') {
				string third_word;
				input >> third_word;
				output << "PROCESSING COMMAND: " << first_word << " " << second_word << " " << third_word << endl;
				SimpleList<string> *n = find_name(stringSimpleList, second_word);
				if (n == NULL) {
					output << "ERROR: This name does not exist!" << endl;
				}
				else {
					n->push(third_word);
				}
			}
			else { output << "ERROR AT PUSH" << endl; }
		}
		// This if statement corresponds to a pop from a stack or a queue
		else if (first_word == "pop") { 
			input.get();
			char second_word_first_char;
			second_word_first_char = input.get(); 
			string cut_second_word;
			input >> cut_second_word; 
			string second_word = second_word_first_char + cut_second_word; 
			//Note that we do not take the third word in this case, since pop has no inputs.
			output << "PROCESSING COMMAND: " << first_word << " " << second_word << endl;
			
			if (second_word_first_char == 'i') {
				// Two checks in this case, whether the list exists, and whether the list is empty
				SimpleList<int> *n = find_name(intSimpleList, second_word);
				if (n == NULL) {
					output << "ERROR: This name does not exist!" << endl;
				}
				else if (n->listIsEmpty()) {
					output << "ERROR: This list is empty!" << endl;
				}
				else {
					output << "Value popped: " << n->pop() << endl;
				}
			}
			
			else if (second_word_first_char == 'd') {
				SimpleList<double> *n = find_name(doubleSimpleList, second_word);
				if (n == NULL) {
					output << "ERROR: This name does not exist!" << endl;
				}
				else if (n->listIsEmpty()) {
					output << "ERROR: This list is empty!" << endl;
				}
				else {
					output << "Value popped: " << n->pop() << endl;
				}
			}
			
			else if (second_word_first_char == 's') {
				SimpleList<string> *n = find_name(stringSimpleList, second_word);
				if (n == NULL) {
					output << "ERROR: This name does not exist!" << endl;
				}
				else if (n->listIsEmpty()) {
					output << "ERROR: This list is empty!" << endl;
				}
				else {
					output << "Value popped: " << n->pop() << endl;
				}
			}
			
			else { output << "ERROR AT POP" << endl; }
			
		}		
		
	}
		return 0;
}

				
				
				
				
		
		
	

	