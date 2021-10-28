//from textbook pg 1101 see notes for ref
#ifndef H_listIterator
#define H_listIterator
#include "linkedList.h"
template <class Type>
class linkedListIterator{
private:
	nodeType<Type> *current;
public:
	linkedListIterator(){current = nullptr}
	//default constructor
	//makes current = null
	
	linkedListIterator(nodeType<Type> *ptr){ current = ptr;}
	//para construct
	//makes current = parameter
	//defined here 
	
	Type operator*(){return current->info;}
	//overlaods  * 
	//returns info from node
	//defined here
	
	linkedListIterator<Type> operator++();
	// overloading ++
	// returns next node unless node == end;
	//defined below

	bool operator==(const linkedListIterator<Type>& right) const;
	//overloading ==
	//check info for info
	//defined below

	bool operator!=(const linkedListIterator<Type>& right)const;
	//as above so below (see prevous memebr)
	//defined below

};


template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(){
	current = current->link;
	//move to next link
	return *this;
}
	
template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right)const {
	return (current == right.current);
	// will return T/F 
}


	
template<class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right)const {
	return (current != right.current);
	// will return T/F 
}
#endif