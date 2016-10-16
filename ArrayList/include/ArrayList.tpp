#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(const int length) : len(length) {
	array = new T[length];
}

template <class T>
ArrayList<T>::ArrayList(const T* collection, const int length) : len(length) {
	array = new T[length];
	for(int i = 0; i < len; i++) {
		array[i] = collection[i];
	}
}

template <class T>
ArrayList<T>::ArrayList(ArrayList<T> &copy) : len(copy.len), array(copy.array) {
	array = new T[len];
	for(int i = 0; i < len; i++) {
		array[i] = copy.get(i);
	}
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete[] array;
}

template <class T>
void ArrayList<T>::add(const T element) {
	add(len, element);
}

template <class T>
const bool ArrayList<T>::add(const int index, const T element) {
	if(index > len) {
		return false;
	}
	len++;
	T* newArray = new T[len];
	for(int i = 0, j = 0; i < len-1; i++, j++) {
		newArray[i] = array[j];
		if(i+1 == index) {
			newArray[i+1] = element;
			i++;
		}
	}
	delete[] array;
	array = newArray;
	return true;
}

template <class T>
void ArrayList<T>::clear() {
	len = 0;
	delete[] array;
	array = new T[0];
}

template <class T>
const bool ArrayList<T>::contains(const T element) {
	if(indexOf(element) == -1) {
		return false;
	}
	return true;
}

template <class T>
const int ArrayList<T>::indexOf(const T element) {
	for(int i = 0; i < len; i++) {
		if(array[i] == element) {
			return i;
		}
	}
	return -1;
}

template <class T>
const T ArrayList<T>::remove(const int index) {
	if(index >= len) {
		return -1;
	}
	if(len == 0) {
		return -1;
	}
	len--;
	T* newArray = new T[len];
	T removed = array[index];
	for(int i = 0, j = 0; i < len+1; i++, j++) {
		if(i == index) {
			i++;
		}
		newArray[j] = array[i];
	}
	delete[] array;
	array = newArray;
	return removed;
}

template <class T>
const bool ArrayList<T>::removeAll(const T element) {
	if(len == 0) {
		return false;
	}
	int newLen = len;
	for(int i = 0; i < len; i++) {
		if(array[i] == element) {
			newLen--;
		}
	}
	if(len == newLen) {
		return false;
	}
	T* newArray = new T[newLen];
	for(int i = 0, j = 0; i < len; i++) {
		if(array[i] != element) {
			newArray[j] = array[i];
			j++;
		}
	}
	len = newLen;
	delete[] array;
	array = newArray;
	return true;
}

template <class T>
std::ostream& operator<< (std::ostream& out, ArrayList<T> &list) {
	if(list.isEmpty()) {
		out << "No list";
	} else {
		for(int i = 0; i < list.size(); i++) {
			out << list.get(i) << " ";
		}
	}
	return out;
}
