// class linkedList.h
// as defined by page 1100-oooo (refrence in notes)
//
#ifndef H_linkedList
#define H_linkedList
#include "nodeType.h"
template <class Type>
class linkedList{
protected://why? why shouldn't it be 'public'
	int count;// ie length
	nodeType<Type> *first;//pointer to first node
	nodeType<Type> *last;//pointer to last
};
//


#endif
