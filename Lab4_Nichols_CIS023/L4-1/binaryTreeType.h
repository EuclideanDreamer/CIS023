/*//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
/
/-----[Program Name: L4-1
/
/-----[Inital Author: Bailey Nichols   
/
/-----[File Name: binaryTree.h
/
/-----[Purpose: this is a header file that contains the binary tree class and the node struct. 
/
/-----[Notes: pretty much all the code is from the textbook.
/
/                         UML
/      struct____nodeType__________
/          |templated type info
/          |pointer to left child
/          |pointer to right child
/           ------------
/               is datatype used in binaryTreeType
/
/
/
/           _____BinaryTreeType_______
/
/           |+|bool|isEmpty()
/           |+|void|inorderTraversal()
/           |+|void|postorderTravrsal()
/           |+|void|preorderTravrsal()
/           |+|int |treeHeight()
/           |+|int |treeLeavesCount
/           |+|int |treeNodesCount
/           |+|void|destroyTree
/           |+|bool|search()
/           |+|void|insert()
/           |+|void|insertNeleteNode()
/           |+|    |binaryTreeType() //constructor
/           |+|    |~binaryTreeType() //destructor
/           |+|void|swapSubTree()
/               ------------------------
/           |#|node|root        //pointer
/               ------------------------
/           |-|void|destroy(root)
/           |-|void|inorder(root)
/           |-|void|preorder(root)
/           |-|void|postorder(root)
/           |-| int|height(root)
/           |-| int|max(int, int)
/           |-| int|nodeCount(root)
/           |-| int|leavesCount(root)
/           |-|void|nonRecursiveTraversal
/               ------------------------
/                   ->binarySearchTreeType
/       
/
/-------------------------------[Change Log]--------------------------------------------------------------------------------/
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
*///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
//preprocessor statements
#pragma once
//including iostream

#include <iostream>
#include <stack>
//Notes:
//Malik, D.S..C++ Programming: Program Design Including Data Structures(MindTap Course List) (p. 1373).Cengage Learning.Kindle Edition.
//this is where all the code in this file comes from with little exception. 


//definition of the node
template <class elemType>
struct nodeType {
	elemType info;
	nodeType<elemType>* lLink;
	nodeType<elemType>* rLink;
};

//definintion of the class
template<class elemType>
class binaryTreeType
{
public:

	bool isEmpty()const;
	//retuns if root is not null

	void inorderTraversal()const;
	//function to call an inorder traversal

	void preorderTraversal()const;
	//it does  it 

	void postorderTraversal()const;
	//

	int treeHeight()const;
	//this function returns an int that is the height of the tree

	int treeNodeCount()const;
	//

	int treeLeavesCount()const;
	//

	void destroyTree();
	//why not 'chopTree' sets root to null

	virtual bool search(const elemType& searchItem)const = 0;
	//this is a virtual decleration if the search function to determine if an item is in the tree

	virtual void insert(const elemType& insertItem) = 0;
	//function to insert in the binary tree

	virtual void deleteNode(const elemType& deleteItem) = 0;
	//function to delete node

	binaryTreeType();

	~binaryTreeType();



	void swapsubtree();


protected:
	nodeType<elemType>* root;

private:
	//swap subtrees
	void swapSubTree(nodeType<elemType>* p);

	void destroy(nodeType<elemType>*& p);

	void inorder(nodeType<elemType>* p)const;

	void preorder(nodeType<elemType>* p)const;

	void postorder(nodeType<elemType>* p)const;

	int height(nodeType<elemType>* p)const;

	int max(int x, int y)const;

	int nodeCount(nodeType<elemType>* p)const;

	int leavesCount(nodeType<elemType>*)const;

	void nonRecursveInTraversal()const;

};
/*
	Nonrecursive Inorder Traversal (){
		1 current = root;

		2 while ( current is not nullptr  and stack is non-empty){
			if (current is not nullptr){
				push current into stack
				current = current lLink;
			}
			else{
				current = stack.top();
				pop stack;
				visit current;
				current = curent rLink;

	}
*/
//as defined on pg 1395
template <class elemType>
void binaryTreeType<elemType>::nonRecursveInTraversal() const {
	std::stack<nodeType<elemType>*> stack; //make std::stack of nodeType pointers
	nodeType<elemType>* current;
	current = root;
	while ((current) || (!stack.empty())) {
		if (current) {
			stack.push(current);
			current = current->lLink;
		}
		else {
			current = stack.top();
			stack.pop();
			//'visit'
			current = current->rLink;
		}
	}
	//std::cout << std::endl;
}


template<class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const{
	std::stack<nodeType<elemType>*> stack; //make std::stack of nodeType pointers
	int n = 0;
	nodeType<elemType>* current;
	current = root;
	while ((current) || (!stack.empty())) {
		if (current) {
			stack.push(current);
			current = current->lLink;
		}
		else {
			current = stack.top();
			stack.pop();
			if ((current->lLink == nullptr) && (current->rLink == nullptr)) {
				n++;
			}
			current = current->rLink;
		}
	}
	//std::cout << std::endl;
	return n;
} 

template<class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType>* p) const{
	return treeLeavesCount();//lol
}


template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType>* p) const{
	int n = 0;
	std::stack<nodeType<elemType>*> stack;
	nodeType<elemType>* current;
	current = p;
	while ((current) || (!stack.empty())) {
		if (current) {
			stack.push(current);
			current = current->lLink;
		}
		else {
			current = stack.top();
			stack.pop();
			n++;
			current = current->rLink;
		}
	}
	//std::cout << std::endl;
	return n;
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = nullptr;
	std::cout << "Bailey Nichols\tL4-1\tL4-1.exe"<<std::endl;
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty()const {
	return (!root);//if root is not false
}

template <class elemType>
void binaryTreeType<elemType> ::inorderTraversal()const {
	inorder(this->root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal()const {
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal()const {
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const {
	return height(root);
}

template<class elemType>
int binaryTreeType<elemType>::treeNodeCount()const {
	return (nodeCount(root));
}

template<class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p) const {
	if (p) {
		inorder(p->lLink);
		std::cout << p->info << " ";
		inorder(p->rLink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType>* p) const {
	if (p) {
		std::cout << p->info << " ";
		preorder(p->lLink);
		preorder(p->rLink);
	}
}

template<class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType>* p) const {
	if (p) {
		postorder(p->lLink);
		postorder(p->rLink);
		std::cout << p->info << " ";
	}
}



template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType>* p) const{
	if (p== nullptr) {
		return 0;
	}
	else {
		return 1 + max(height(p->lLink), height(p->rLink));
	}
}

template<class elemType>
int binaryTreeType<elemType>::max(int x, int y) const {
	if (x >= y) {
		return x;
	}
	else {
		return y;
	}
}

template<class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>*& p) {
	if (p) {
		destroy(p->lLink);
		destroy(p->rLink);
		delete p;
		p = nullptr;
		return;
	}
}

template<class elemType>
void binaryTreeType<elemType>::destroyTree() {
	destroy(root);
}
/*
//overloading assignemt operator
template<class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>& otherTree) {
	if (this != &otherTree) {
		if (root) {
			destroy(root);
		}if(otherTree.root) {
			root = nullptr;
		}
		else {
			copyTree(root, otherTree.root);
		}
		return *this;
	}
}
*/

// just do another traversal and swap the subtrees using a temporary node
template<class elemType>
void binaryTreeType<elemType>::swapSubTree(nodeType<elemType>* p) {
	nodeType<elemType>* temp = nullptr;
	if (p) {
		//first the recursive traversal a la xxx-order() defined above by textbook
		//now swap the trees

		temp = p->lLink;
		p->lLink = p->rLink;
		p->rLink = temp;
		swapSubTree(p->lLink);
		swapSubTree(p->rLink);
	} 
}

//and just like with the other recursive traversal functions we just call it with a simple function
template<class elemType>
void binaryTreeType<elemType>::swapsubtree() {
	swapSubTree(root);
}
