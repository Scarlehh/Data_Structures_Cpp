#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <ostream>

template <class T>
class ArrayList {
 private:
	T* array;
	int len;

 public:
	ArrayList(const int length = 0);
	ArrayList(const T* collection, const int length);
	ArrayList(ArrayList &copy);
	virtual ~ArrayList();

	void add(const T element);
	const bool add(const int index, const T element);
	void clear();
	const bool contains(const T element);
	const int indexOf(const T element);
	const T remove(const int index);
	const bool removeAll(const T element);

	inline T& get(const int index) { return array[index]; }
	inline const T* getCollection() { return array; }
	inline const bool isEmpty() { if(len == 0) return true; return false; };
	inline const int size() { return len; };

	template <class U>
	friend std::ostream& operator<< (std::ostream& out, ArrayList<U>& list);
};

#include "ArrayList.tpp"

#endif
