#ifndef SINGLE_LINKED_LIST_H_
#define SINGLE_LINKED_LIST_H_


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


struct Node {
	string data;
	Node* next;

};

class Single_Linked_List {
private:



	Node* headPtr;
	Node* tailPtr;
	size_t num_items;

public:

	Single_Linked_List();

	void push_front(string item);
	void push_back(string item);
	void pop_front();
	void pop_back();
	string front();
	string back();
	size_t find(const string item);
	bool remove(size_t index);
	void insert(size_t index, const string item);
	bool empty();

};



#endif