/*
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Header name    :      linkedList.h                   * 
'*                                                                     * 
'* Written by      : Bailey Nichols                                     * 
'*                                                                     * 
'* Purpose         :         no idea this could just be a struct really*                              * 
'*                                                                     * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 11/08/12      Nichols 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
// class linkedList.h
// as defined by page 1100-oooo (refrence in notes)
//
#ifndef H_linkedList
#define H_linkedList
#include "nodeType.h"
template <class Type>
class linkedList{
// protected://why? why shouldn't it be 'private'?
	int count;// ie length
	nodeType<Type> *first;//pointer to first node
	nodeType<Type> *last;//pointer to last
public:
	//overloaded operators
	//equality
	const linkedList<Type>& operator=(const linkedList<Type>&);

	//intalize list
	void initializeList();

	//check if list is empty
	bool isEmptyList() const;

    //prints info in each node
    void print() const;

    //find lenght of list
    int length()const;

    //end list
    void destroyList();

    //return the front of list
    //list must exist
    //if list does not exist, program terminates, otherwise first elemnt is returned
    Type front()const;
 
    //as above so below(ie see above)
    Type back() const;

    //bool search
    virtual bool search(const Type& searchItem) const = 0;

    //insert node at first 
    virtual void insertFirst(const Type& newItem)=0;

    //insert node at last
    virtual void insertLast(const Type& newItem)=0;

    //deletes item from list
    virtual void deleteNode(const Type& deleteItem)=0;

    //default constructor
    //lirst,last = nullptr count =0;
    linkedList();

    //copy constructor
    linkedList(const linkedList<Type>& otherList);

    ~linkedList();
};

	//overloaded operators
	//equality
	template <class Type>
	const linkedList<Type>& linkedList<Type>::operator=(const linkedList<Type>& otherList){
		if(this != &otherList){
			destroyList();
			initializeList();
			nodeType<Type> *current = otherList.first;
			while(current != nullptr){
				insertLast(current->info);
				current = current->link;
			}
		}
		return *this;
	}

	//intalize list
	template <class Type>
	void linkedList<Type>::initializeList(){
		first = nullptr;
		last = nullptr;
		count = 0;
	}

	//check
	template <class Type>
	bool linkedList<Type>::isEmptyList() const{
		return first == nullptr;
	}

	//prints info in each node
	template <class Type>
	void linkedList<Type>::print() const{
		nodeType<Type> *current;
		current = first;
		while(current != nullptr){
			cout << current->info << endl;
			current = current->link;
		}
	}

	//find lenght of list
	template <class Type>
	int linkedList<Type>::length()const{
		return count;
	}
	
	//end list
	template <class Type>
	void linkedList<Type>::destroyList(){
		nodeType<Type> *current;
		while(first != nullptr){
			current = first;
			first = first->link;
			delete current;
		}
		last = nullptr;
		count = 0;
	}

	//return the front of list
	//list must exist
	//if list does not exist, program terminates, otherwise first elemnt is returned
	template <class Type>
	Type linkedList<Type>::front()const{
		if(first == nullptr){
			cout << "List is empty" << endl;
			exit(1);
		}
		return first->info;
	}

	//as above so below(ie see above)
	template <class Type>
	Type linkedList<Type>::back() const{
		if(last == nullptr){
			cout << "List is empty" << endl;
			exit(1);
		}
		return last->info;
	}

	//bool search
	template <class Type>
	bool linkedList<Type>::search(const Type& searchItem) const{
		bool found = false;
		nodeType<Type> *current;
		current = first;
		while(current != nullptr && !found){
			if(current->info == searchItem){
				found = true;
			}
			else{
				current = current->link;
			}
		}
		return found;
	}

	//insert node at first
	template <class Type>
	void linkedList<Type>::insertFirst(const Type& newItem){
		nodeType<Type> *newNode;
		newNode = new nodeType<Type>;
		newNode->info = newItem;
		newNode->link = first;
		first = newNode;
		count++;
		if(last == nullptr){
			last = newNode;
		}
	}

	//insert node at last
	template <class Type>
	void linkedList<Type>::insertLast(const Type& newItem){
		nodeType<Type> *newNode;
		newNode = new nodeType<Type>;
		newNode->info = newItem;
		newNode->link = nullptr;
		if(first == nullptr){
			first = newNode;
			last = newNode;
		}
		else{
			last->link = newNode;
			last = newNode;
		}
		count++;
	}

	//deletes item from list
	template <class Type>
	void linkedList<Type>::deleteNode(const Type& deleteItem){
		nodeType<Type> *current;
		nodeType<Type> *trailCurrent;
		bool found;
		if(first == nullptr){
			cout << "Cannot delete from an empty list" << endl;
			return;
		}
		if(first->info == deleteItem){
			current = first;
			first = first->link;
			count--;
			if(first == nullptr){
				last = nullptr;
			}
			delete current;
			return;
		}
		found = false;
		trailCurrent = first;
		current = first->link;
		while(current != nullptr && !found){
			if(current->info == deleteItem){
				found = true;
			}
			else{
				trailCurrent = current;
				current = current->link;
			}
		}
		if(found){
			trailCurrent->link = current->link;
			count--;
			if(last == current){
				last = trailCurrent;
			}
			delete current;
		}
		else{
			cout << "The item to be deleted is not in the list" << endl;
		}
	}

	//default constructor
	template <class Type>
	linkedList<Type>::linkedList(){
		initializeList();
	}

	//copy constructor
	template <class Type>
	linkedList<Type>::linkedList(const linkedList<Type>& otherList){
		nodeType<Type> *newNode;
		nodeType<Type> *current;
		if(otherList.first == nullptr){
			first = nullptr;
			last = nullptr;
			count = 0;
		}
		else{
			copyList(otherList.first, newNode);
			}
	}
//end of class
#endif
