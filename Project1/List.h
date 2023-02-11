#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename T>
class List
{
public:
	List(); //default constructor
	List(T* array, int size); //construct list from given array
	List(T item, int occurrences); //construct list from occurences of specific item
	List(T item); //converts single value into list of size 1

	virtual ~List(); //destructor

	T getItem(int index) const final; //gets item from specific index (returns item)

	int getSize(); //returns size of list

	virtual void append(T item); //appends single item to end of list
	virtual void append(T items[], int size); //appends sequence of items to end of list
	virtual void append(List items); //appends list of items to end of list

	virtual void insert(T item, int index); //insert item at specific index
	virtual void insert(T items[], int size, int index); //insert sequence of items at index

	void remove(T item, bool all=False); //removes item from list, if all==True then removes all occurrences

	virtual void sort(bool asc=True); //sort items, default is ascending but if false then descending

	virtual int search(T item) const final; //search for an item in the list (returns index)

	//insert list into output stream
	//extract list from input stream


	void expand(); //expand list capacity by 10

private:
	T* list; //list of items
	int listSize; //number of items currently in list
	int cap; //number of items that can be in list

};

class SortedList {};

#endif