/*//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
/
/-----[Program Name: L4-1
/
/-----[Inital Author: Bailey Nichols   
/
/-----[File Name: binarySearchTree.h
/
/-----[Purpose: this is the implimentation of the binary search tree 
/
/-----[Notes:
/
//-------------------------------[Change Log]--------------------------------------------------------------------------------/
/--------{Date}---------{Name of Author}----{Version Number}-------{Status}------------------------------------------------|
/     11/21/2021         Bailey Nichols           0                 Non-Working
/     11/24/2021         Bailey Nichols           0                 Non-Working
/     11/27/2021         Bailey Nichols           0                 Fail
/     11/30/2021         Bailey Nichols           0                 Non-Working
/     12/3/2021          Bailey Nichols           0                 Non-Working
/     12/5/2021          Bailey Nichols           0                 Fail
/     12/7/2021          Bailey Nichols           0                 Fail
/     12/10/2021         Bailey Nichols           0                 Inital working verson still contains bugs
/
/
/
/
/                           UML
/               
/               ____binarySearcTree______
/               |+|bool|search(item)
/               |+|void|insert(item)
/               |+|void|deleteNode(item)
/               |+|void|preorder(node, binarySearchtreetype)
/               |+|void|postorder(node, binarySearchtreetype)
/               |+|void|preorderTraversal(binarySearchtreetype)
/               |+|void|postrderTraversal(binarySearchtreetype)
/                   ----------------------------
/               |-|void|deleteFromTree(node)
/
/
*///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
//preprocessor statements
#pragma once
#include "binaryTreeType.h"

template<class elemType>
class binarySearchTreeType: public binaryTreeType<elemType>
{
public:
	bool search(const elemType& searchItem) const;
	//to find template <class elemType> in tree 
	//returns bool

	void insert(const elemType& insertItem);
	//function to insert elemType in BST

	void deleteNode(const elemType& deleteItem);
	//

	//Overloaded functions made to follow assignment directions
	void preorder(nodeType<elemType>* p, binarySearchTreeType<elemType>& t)const;

	void postorder(nodeType<elemType>* p, binarySearchTreeType<elemType>& t)const;

	void preorderTraversal(binarySearchTreeType<elemType>& t)const;


	void postorderTraversal(binarySearchTreeType<elemType>& t)const;



private:
	void deleteFromTree(nodeType<elemType>*& p);
	//deletes node passed as parameter
};

/*
search in psudocode

if root is null
	cannot search tree return false
else{
	current = root;
	while(current != null && current is not found){
		if (current->info == searchInfo){
			found;
		}
		else {
			if(current->info > searchItem){
				current = current->lLink;
			}
			else{
				current = current->rLink;
			}
		}
	}
}
*/
//now in c++
template<class elemType>
bool binarySearchTreeType<elemType>::search(const elemType& searchItem)const {
	nodeType<elemType>* current;
	bool found = false;
	if (!this->root) {
		std::cout << "Cannot search empty tree" << std::endl;
	}
	else {
		current = this->root;

		while (current != nullptr && !found) {
			if (current->info == searchItem) {
				found = true;
			}
			else if(current->info > searchItem) {
				current = current->lLink;
			}
			else {
				current = current->rLink;
			}
		}
	}
	return found;
}

/*
Insert in SudoCode
A. Create a newNode and copy insertItem into the newNode, then set NewNode children to null

B. if the root is null, the tree is empty and so make newNode = root
else{
	current = root;
	while (current is not null){
		trailCurrent = current
		if(current->info ==InsertItem){
			cout << bad move try again
			return;
		}
		else{
			if (trailCurrent->info > insertItem){
				make the new node to the left of trailcurrent
			}
			else
				make the new node to the right of trailcurrent
		}

*/ 
//now again in c++
template <class elemType>
void binarySearchTreeType<elemType>::insert(const elemType& insertItem) {
	nodeType<elemType>* current;
	nodeType<elemType>* trailCurrent = nullptr;
	nodeType<elemType>* newNode;

	newNode = new nodeType<elemType>;
	newNode->info = insertItem;
	newNode->lLink = nullptr;
	newNode->rLink = nullptr;
	if (this->root == nullptr) {
		this->root = newNode;

		return;
	}
	else {
		current = this->root;
		
		while (current != nullptr) {

			trailCurrent = current;
			if (current->info == insertItem) {
				std::cout << "Insert Fail, Item is already in tree." << std::endl;
				return;
			}
			else if (current->info > insertItem) {
				current = current->lLink;
			}
			else {
				current = current->rLink;
			}
		}//this while loop 'drives' the function through the tree
		if (trailCurrent->info > insertItem) {
			trailCurrent->lLink = newNode;
		}
		else {
			trailCurrent->rLink = newNode;
		}
	}
}

//see page 1387-1390 for DeleteNode Explination
template<class elemType>
void binarySearchTreeType<elemType>::deleteFromTree(nodeType<elemType>* &p) {
	nodeType<elemType>* current;
	nodeType<elemType>* trailCurrent;
	nodeType<elemType>* temp;
	
	if (p == nullptr) {
		std::cout << "Error link to be deleted does not exist" << std::endl;
	}
	else if (p->lLink == nullptr && p->rLink == nullptr) {
		temp = p;
		p = nullptr;
		delete temp;
	}
	else if (p->lLink == nullptr) {
		temp = p; 
		p = temp->rLink;
		delete temp;
	}
	else if (p->rLink == nullptr) {
		temp = p;
		p = temp->lLink;
		delete temp;
	}
	else {
		current = p->lLink;
		trailCurrent = nullptr;

		while (current->rLink != nullptr) {
			trailCurrent = current;
			current = current->rLink;
		}//end while

		p->info = current->info;

		if (trailCurrent == nullptr) {
			p->lLink = current->lLink;
		}
		else {
			trailCurrent->rLink = current->lLink;
		}

		delete current;
	}
}

template <class elemType>
void binarySearchTreeType<elemType>::deleteNode(const elemType& deleteItem) {
	nodeType<elemType>* current;
	nodeType<elemType>* trailCurrent;
	bool found = false;

	if (this->root == nullptr) {
		std::cout << "deleteNode Fail, cannot delete from empty tree" << std::endl;
	}
	else {
		current = this->root;
		trailCurrent = this->root;
		while (current != nullptr && !found) {
			if (current->info == deleteItem) {
				found = true;
			}
			else {
				trailCurrent = current;
				if (current->info > deleteItem) {
					current = current->lLink;
				}
				else {
					current = current->rLink;
				}
			}
		}//end while

		if (current == nullptr) {
			std::cout << "deleteNode Fail, item is not in tree"<<std::endl;
		}
		else if(found) {
			if (current == this->root) {
				deleteFromTree(this->root);
			}
			else if (trailCurrent->info > deleteItem) {
				deleteFromTree(trailCurrent->lLink);
			}
			else {
				deleteFromTree(trailCurrent->rLink);
			}
		}
		else {
			std::cout << "deleteNode Fail, item is not in tree" << std::endl;
		}
	}
}


//these are all just slightly modifed functions from chapter 19

template <class elemType>
void binarySearchTreeType<elemType>::preorder(nodeType<elemType>* p, binarySearchTreeType<elemType>& t)const {
	if (p) {
		t.insert(p->info);
		std::cout << p->info << " ";
		preorder(p->lLink, t);
		preorder(p->rLink, t);
	}
}

template <class elemType>
void binarySearchTreeType<elemType>::postorder(nodeType<elemType>* p, binarySearchTreeType<elemType>& t)const {
	if (p) {
		postorder(p->lLink, t);
		postorder(p->rLink, t);
		t.insert(p->info);
		std::cout << p->info << " ";
	}
}


template <class elemType>
void binarySearchTreeType<elemType>::preorderTraversal(binarySearchTreeType<elemType>& t)const {
	preorder(this->root, t);
}

template <class elemType>
void binarySearchTreeType<elemType>::postorderTraversal(binarySearchTreeType<elemType>& t)const {
	postorder(this->root, t);
}
