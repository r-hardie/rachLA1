#include "List.h"
#include <iostream>

template <typename T>
List<T>::List() {
	listSize = 0;
	cap = 10;
	T* list = new T[cap];
}

template<typename T>
List<T>::List(T* array, int size)
{
	listSize = size;
	cap = size; //is making cap the exact right size the most efficient?
	T* list = new T[cap];
	
	for (int i = 0; i < size; i++) {
		list[i] = array[i];
	}
}

template <typename T>
List<T>::List(T item, int occurrences) {
	listSize = occurrences;
	cap = occurrences;
	T* list = new T[cap];

	for (int i = 0; i < occurrences; i++) {
		list[i] = item;
	}
}

template <typename T>
List<T>::List(T item) {
	listSize = 1;
	cap = 1;
	T* list = new T[cap];
	list[0] = item;
}

template <typename T>
List<T>::~List() {
	delete[] list;
}

template<typename T>
T List<T>::getItem(int index) const
{
	T selected = list[index];
	return selected;
}

template<typename T>
int List<T>::getSize()
{
	return listSize;
}

template<typename T>
void List<T>::append(T item)
{
	if (listSize + 1 >= cap) {
		this->expand();
	}

	list[listSize] = item;
	listSize++;
}

template<typename T>
void List<T>::append(T items[], int size)
{
	while (listSize + size >= cap) {
		this.expand();
	}

	for (int i = 0; i < size; i++) {
		list[listSize] = items[i];
		listSize++;
	}
}

template<typename T>
void List<T>::append(List items) 
{
	while (this->listSize + items->listSize >= this->cap) {
		this->expand();
	}

	for (int i = 0; i < items->listSize; i++) {
		this->list[listSize] = items->list[listSize];
		this->listSize++;
	}
}


//would probably be a good idea to rewrite the insert functions 
//so instead of using a seperate array it uses more insertion sort
template<typename T>
void List<T>::insert(T item, int index)
{
	if (this->listSize + 1 >= this->cap) {
		this->expand();
	}

	T* templist = new T[this->listSize - index];

	for (int i = index, j=0; i < this->listSize; i++, j++) {
		templist[j] = this->list[i];
	}

	this->list[index] = item;
	this->listSize++;

	for (int i = index + 1, j = 0; i < this->listSize; i++,j++) {
		this->list[i] = templist[j];
	}

	delete[] templist;
}

template<typename T>
void List<T>::insert(T items[], int size, int index)
{
	while (this->listSize + size >= cap) {
		this->expand();
	}

	int tempSize = this->listSize + size - index;
	T* templist = new T[tempSize];

	for (int i = index, j = 0; i < this->listSize; i++, j++) {
		templist[j] = this->list[i];
	}

	for (int i = 0, j = index; i < size; i++, j++) {
		this->list[j] = items[i];
		this->listSize++;
	}

	for (int i = 0; i < tempSize; i++) {
		this->list[listSize] = templist[i];
		this->listSize++;
	}

	delete[] templist;
}

template <typename T>
void List<T>::expand() 
{
	T* templist = new T[listSize];
	for (int i = 0; i > listSize; i++) {
		templist[i] = list[i];
	}

	delete[] list;
	cap += 10;
	list = new T[cap];
	
	for (int i = 0; i < listSize; i++) {
		list[i] = templist[i];
	}
	delete[] templist;
}


