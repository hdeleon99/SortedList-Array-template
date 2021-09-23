
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = -1;  // 0
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    int midPoint;
    int first = 0;
    int last = length - 1;

    while (first <= last){
        midPoint = (first + last) / 2;

        if (someItem < info[midPoint])
            last = midPoint - 1;
        else if (someItem > info[midPoint])
            first = midPoint + 1;
        else {
            return true;
        }
    }
    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    int location = 0;
    // find proper location for new element
    for (location = 0; location < length; location++){
        if (info[location] > item)
            break;
    }

    // make room for new element in sorted list
    for (int index = length; index > location; index--)
        info[index] = info[index - 1];

    info[location] = item;
    length++;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    int location;
    // find item to delete
    for (location = 0; location < length; location++){
        if (info[location] == item)
            break;
    }
    // remove space occupied by item, and shift elements accordingly
    for (int i = location + 1; i < length; i++){
        info[i-1] = info[i];
    }
    --length;
}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}

