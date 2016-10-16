#include <cxxtest/TestSuite.h>
#include "ArrayList.h"

class TestArrayList : public CxxTest::TestSuite {
public:
	void testGetCollection(void) {
		int len = 4;
		int arr[len] = {1, 2, 3, 4};
		ArrayList<int> list(arr, len);
		TS_ASSERT_SAME_DATA(list.getCollection(), arr, len);
	}
	
	void testGet(void) {
		int len = 4;
		int arr[len] = {1, 2, 3, 4};
		ArrayList<int> list(arr, len);
		TS_ASSERT_EQUALS(list.get(0), arr[0]);
		TS_ASSERT_EQUALS(list.get(1), arr[1]);
		TS_ASSERT_EQUALS(list.get(2), arr[2]);
		TS_ASSERT_EQUALS(list.get(3), arr[3]);
	}
	
	void testAppend(void) {
		ArrayList<int> list;
		list.add(3);
		TS_ASSERT_EQUALS(list.get(0), 3);
		list.add(4);
		TS_ASSERT_EQUALS(list.get(0), 3);
		TS_ASSERT_EQUALS(list.get(1), 4);
	}

	void testAdd(void) {
		ArrayList<int> list;
		list.add(0, 2);
		TS_ASSERT_EQUALS(list.get(0), 2);
		list.add(0, 1);
		TS_ASSERT_EQUALS(list.get(0), 1);
		TS_ASSERT_EQUALS(list.get(1), 2);
		list.add(1, 4);
		TS_ASSERT_EQUALS(list.get(0), 1);
		TS_ASSERT_EQUALS(list.get(1), 4);
		TS_ASSERT_EQUALS(list.get(2), 2);
		list.add(5);
		TS_ASSERT_EQUALS(list.get(0), 1);
		TS_ASSERT_EQUALS(list.get(1), 4);
		TS_ASSERT_EQUALS(list.get(2), 2);
		TS_ASSERT_EQUALS(list.get(3), 5);
	}

	void testRemove(void) {
		int len = 6;
		int arr[len] = {6, 5, 4, 3, 2, 1};
		ArrayList<int> list(arr, len);
		TS_ASSERT_EQUALS(list.remove(0), 6);
		TS_ASSERT_EQUALS(list.remove(10), -1);
		TS_ASSERT_EQUALS(list.remove(4), 1);
		TS_ASSERT_EQUALS(list.remove(2), 3);
	}

	void testRemoveAll(void) {
		int len = 6;
		int arr[len] = {3, 4, 4, 3, 2, 4};
		ArrayList<int> list(arr, len);
		TS_ASSERT(list.removeAll(4));
		TS_ASSERT(list.removeAll(2));
		TS_ASSERT(!list.removeAll(4));
		TS_ASSERT(!list.removeAll(0));
	}

	void testIsEmpty(void) {
		ArrayList<int> list;
		TS_ASSERT(list.isEmpty());
		list.add(3);
		TS_ASSERT(!list.isEmpty());
	}

	void testClear(void) {
		int len = 5;
		int arr[5] = {1, 2, 3, 4, 5};
		ArrayList<int> list(arr, len);
		TS_ASSERT_SAME_DATA(list.getCollection(), arr, len);
		list.clear();
		TS_ASSERT(list.isEmpty());
	}

	void testContains(void) {
		int len = 6;
		int arr[len] = {6, 5, 4, 3, 2, 1};
		ArrayList<int> list(arr, len);
		TS_ASSERT(list.contains(4));
		TS_ASSERT(list.contains(1));
		TS_ASSERT(list.contains(6));
		TS_ASSERT(!list.contains(8));
		TS_ASSERT(!list.contains(-3));

		char chArr[len] = {'a', 'b', 'c', 'd', 'e', 'f'};
		ArrayList<char> charList(chArr, len);
		TS_ASSERT(charList.contains('a'));
		TS_ASSERT(!charList.contains('H'));
	}

	void testIndexOf(void) {
		int len = 6;
		int arr[len] = {6, 5, 4, 3, 2, 1};
		ArrayList<int> list(arr, len);
		TS_ASSERT_EQUALS(list.indexOf(6), 0);
		TS_ASSERT_EQUALS(list.indexOf(1), 5);
		TS_ASSERT_EQUALS(list.indexOf(4), 2);
		TS_ASSERT_EQUALS(list.indexOf(9), -1);

		char chArr[len] = {'a', 'b', 'c', 'd', 'e', 'f'};
		ArrayList<char> charList(chArr, len);
		TS_ASSERT_EQUALS(charList.indexOf('a'), 0);
		TS_ASSERT_EQUALS(charList.indexOf('A'), -1);
	}
};
