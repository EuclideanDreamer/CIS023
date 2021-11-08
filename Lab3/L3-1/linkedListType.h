/*
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Header    :         LinkedlistType,h                                     * 
'*                                                                     * 
'* Written by      : Bailey Nichols                                     * 
'*                                                                     * 
'* Purpose         :                                   * 
'*                                                                     * 
'* Inputs          :    
'*                                                                     * 
'* Outputs         : 
'*                                                                     * 
'* Calls           :  
'*                                                                     * 
'* Structure       : BEGIN                                             * 
'*                        
'*                   STOP                                              * 
'*                        End of Program                               * 
'*                                                                     * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 06/06/12      Nichols 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
//defined on page 1104-1105 in text see notes for ref
#ifndef H_listType
#define H_listType
#include "linkedListIterator.h"
template<class Type>
class linkedListType
{
private:
    //function to copy list
    void copyList(const linkedListType<Type>& otherlist);
protected:
    int count; //number of items

    nodeType<Type> *first;
    nodeType<Type> *last;
public:
    //overloading list
    const linkedListType<Type>& operator = (const linkedListType<Type>&);

    //initalizing list
    //postcondtion first = nullptr, last = nullptr, count =0;
    void initializeList();

    //check if there is stuff in list
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

    //function to return an iterator at the beginning of the list;
    linkedListIterator<Type>begin();

    //as above so below, what is a beginning but end to another through 
    linkedListIterator<Type>end();

    //default constructor
    //lirst,last = nullptr count =0;
    linkedListType(/* args */);

    //copy constructor
    linkedListType(const linkedListType<Type>& otherList);

    ~linkedListType();
};


template <class Type>
bool linkedListType<Type>::isEmptyList() const{
    return (first == nullptr);
}

template <class Type>
linkedListType<Type>::linkedListType(){
    first = nullptr;
    last = nullptr;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList(){
    nodeType<Type> *temp;//this is a pointer used to deallocate memory //why not use free()
    while (first != nullptr){
        temp = first;
        first = first->link;
        delete temp;
    }
}

template<class Type>
void linkedListType<Type>::initializeList(){
    destroyList(); //if list has any members destroy them ??
}

template <class Type>
void linkedListType<Type>::print() const {
    nodeType<Type> *current; //pointer to use as temp to traverse list

    current = first;

    while ( current != nullptr){
        cout << current->info << " ";
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const {
    return count;
}

template<class Type>
Type linkedListType<Type>::front() const{
    assert(first != nullptr);

    return first->info;
}

template<class Type>
Type linkedListType<Type>::back() const{
    assert(last != nullptr);

    return last->info;
}

template<class Type>
linkedListIterator<Type> linkedListType<Type>::begin(){
    linkedListIterator<Type> temp(first);
    return temp;
}

template<class Type>
void linkedListType<Type>::copyList( const linkedListType<Type> & otherList){
    nodeType<Type> *newNode; //pointers to use below for 
    nodeType<Type> *current; //memory agebra 
    if (first != nullptr)
    {
        destroyList(); //if the list has contents destroy it
    }
    if(otherList.first == nullptr){
        first = nullptr; //if empty init list
        last = nullptr;
        count=0;
    }
    else{
        current = otherList.first;//current points a list to be copied
        count = otherList.count;// get count from list
        first->info = current->info; //transfer info
        first->link = nullptr;       //set link to NULL
        last=first;                  //set last to first
        current = current->link; //make current point to next node

        while(current != nullptr){
            newNode = new nodeType<Type>;//make new node 
            newNode->info = current->info; //transfer info 
            newNode->link = nullptr;   //make link null

            last->link = newNode; //using pointer assignment
            last = newNode; //again

            current = current->link; //and again

        }
    }
}

template<class Type>
linkedListType<Type>::~linkedListType(){
    destroyList();//oh i wonder what this does it couldn't destroy the list
}

template<class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList){
    first = nullptr; //first is null to open new list and stop any overwriting
    copyList(otherList);//copy list
}

template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator= (const linkedListType<Type>& otherList){
    if(this != &otherList){//if self == other do nothing 
        copyList(otherList);//copy
    }
    return *this;//return *newList
}
#endif
