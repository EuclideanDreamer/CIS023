/*
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Header Name     : Unorderedlinkedlist.h                             * 
'*                                                                     * 
'* Written by      : Bailey Nichols                                    * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 11/08/12      Nichols 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
//from page 1111 of textbook (paraphased): 
#ifndef H_unorderedListType
#define H_unorderedListType
#include "linkedList.h"

template<class Type>
class unorderedLinkedList:public linkedList<Type> {
public:
    bool search(const Type& searchItem) const;
    //bool to see if item is list 

    void insertFirst(const Type& newItem);
    //count++ item is inserted at beginning

    void insertLast(const Type& newItem);
    //count++ item is inserted at end

    void deleteNode(const Type& deleteItem);
    //i wonder by jove what a function called delete does? 
};

template<class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem)const {
    nodeType<Type> *current;
    current = first;

    while (current != nullptr){ //while current is not null if search item found cool
        if(current->info == searchItem){
            found = true;
        }else{// if not move to next item
            current = current->link;
        }
    }
    return found;
}

/*
template<class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem)const {
    nodeType<Type> *current;

    current = first;

   while (current != nullptr){ //while current is not null if search item found cool
        if(current->info == searchItem){
            return true;
        }else{// if not move to next item
            current = current->link;
        }
    }
    return false;
}
*/

template<class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem){
    newNode = new nodeType<Type>;

    newNode->link = first;
    first = newNode;
    count++;
    if (last == nullptr){
        last = newNode;
    }
}
template<class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem){
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;

    newNode->info = newItem;
    newNode->link = nullptr; 

    if(first == nullptr){
        first = newNode;
        last = newNode;
        count++;
    }else{
        last->link = newNode;
        last = newNode;

        count++;
    }
}

template<class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem){
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;

    bool found;

    if (first == nullptr){
        cout<< "Cannot delete from empty list"<<endl;
    }else{
        if(first->info == deleteItem){
            current = first;
            first = first->link;
            count--;
            if(first == nullptr){ // list has only one  
                last = nullptr;
            }
            delete current;
        }else{
            found =false;
            trailCurrent = first;

            current = first->link;

            while (current != nullptr && found){
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else{
                    found = true;
                }
            }
            if (found)
            {
                trailCurrent->link = current->link;
                count--;

                if(last==current){
                    last=trailCurrent;
                }
                delete current;
            }else{
                cout<<"The item to be deleted is not in the list"<<endl;
            }
        }
    }
}
#endif