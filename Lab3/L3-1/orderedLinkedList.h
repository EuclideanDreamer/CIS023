//program defiend in textbook see notes for refrence 
#ifndef H_orderedList
#define H_orderedList
#include "unorderedLinkedList.h"
template<typename Type>//why no typename? 
class orderedLinkedList:public linkedListType<Type>{
public:
    bool search(const Type& searchItem)const;
    //bool returned if item is in list or not

    void insert(const Type& newItem);
    //puts new item in list count++
    
    void insertFirst(const Type& newItem);
    //inserst new item at last
    
    void insertLast(const Type& newItem);
    //inserst new item at last

    void deleteNode(const Type& deleteItem);
    //it deletes stuff
};

template<class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem)const{
    bool found = false;
    nodeType<Type> *current;
    current = first;
    while (current != nullptr && !found){
        if(current->info >= search){
            found = true; 
        }else{
            current = current->link;
        }
    }
    if (found)
    {
        found = (current->info == searchItem);
    }
    return found;
}

template<class Type>
void orderedLinkedList<Type>::insert(const Type& newItem){
    nodeType<Type> *current;//pointers and stuff for more memory algebra
    nodeType<Type> *trailCurrent = nullptr;
    nodeType<Type> *newNode;
    bool found;
    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;
    //
    if (first == nullptr){ //case 1
        first = newNode;
        last = newNode;
        count++;
    }else{
        current = first;
        found = false;
        while (current != nullptr && !found){
            if (current->info >= newItem){
                current = current->link;
                found = true;
            }else{
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == first){ // case 2
            newNode->link = first;
            first= newNode;
            count++;
        }else{                 //case 3
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == nullptr){
                last = newNode;
            }
            count++;
        }
    }
}

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem){
    insert(newItem);//using insertNode ??
}

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem){
    insert(newItem);//using insertNode ??
}

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem){
    nodeType<Type> *current;//pointers for mermory algebra
    nodeType<Type> *trailCurrent = nullptr;
    bool found;

    if(first == nullptr){//case 1
        cout << "cannot delete from empty list"<<endl;
    }else{
        current = first;
        found = false;

        while (current != nullptr && !found){//search list
            if (current->info >= deleteItem){
                found = true;
            }else{
                trailCurrent = current;
                current = current->link;
            }
            
        }
        if (current == nullptr){//case 4
            cout << "The item to be deleted is not in the list"<<endl;
        }else{
            if(current->info == deleteItem){//if item is in list
                if (first == current){//case 2
                    first = first->link;
                    if(first == nullptr){
                        last = nullptr;
                    }
                    delete current;
                }
                count--;
            }
        }else{
            cout << "The item to be deleted is not in the list"<<endl;
        }
    }
}
#endif