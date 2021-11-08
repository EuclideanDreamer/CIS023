/*
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Program name    :  mystack.h                                               * 
'*                                                                     * 
'* Written by      : Bailey Nichols                                     * 
'*                                                                     * 
'* Purpose         :   The purpose of this program is to                             * 
'*                                                                     * 
'*                                                                     * 
'* Structure       : BEGIN                                             * 
'*                        while not at the end of the data             *
'*                            1 init the stack     
                              2 process the expression
                              3 output result
                              4 get next expression                    *
'*                   STOP                                              * 
'*                        End of Program                               * 
'*                                                                     * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 11/08/12      Nichols 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
template <class T>
class stackNode{    
    public:
        stackNode();
        stackNode(T data, stackNode<T> *next);
        T getData();
        stackNode<T> *getNext();
        void setData(T data);
        void setNext(stackNode<T> *next);
        
    private:
        T data;
        stackNode<T> *next;
};
//null constructor
template <class T>
stackNode<T>::stackNode(){
    this->data = nullptr;
    this->next = nullptr;
}
// Constructor
template <class T>
stackNode<T>::stackNode(T data, stackNode<T> *next){
    this->data = data;
    this->next = next;
}

//getters
//get data
template <class T>
T stackNode<T>::getData(){
    return this->data;
}

//get next 
template <class T>
stackNode<T> *stackNode<T>::getNext(){
    return this->next;
}

//setters
//set data
template <class T>
void stackNode<T>::setData(T data){
    this->data = data;
}

//set next
template <class T>
void stackNode<T>::setNext(stackNode<T> *next){
    this->next = next;
}

//line for readability
//------------------------------------------------------

//stack class
template <class T>
class stack{
    public:
        //stack utilities
        //constructor
        stack();
        //destructor
        ~stack();
        //clear
        void clear();
        //------------------------------------------------------------------
        //stack operations
        //push
        void push(T data);
        //pop
        T pop();
        //peek
        T peek();
        //isEmpty
        bool isEmpty();
        //print stack
        void print();
        
    private:
        stackNode<T> *top;
};

//null constructor
template <class T>
stack<T>::stack(){
    this->top = nullptr;
}

//destructor
template <class T>
stack<T>::~stack(){
    stackNode<T> *temp;
    while(this->top != nullptr){
        temp = this->top;
        this->top = this->top->getNext();
        delete temp;
    }
}
//clear
template <class T>
void stack<T>::clear(){
    stackNode<T> *temp;
    while(this->top != nullptr){
        temp = this->top;
        this->top = this->top->getNext();
        delete temp;
    }
}
//------------------------------------------------------------------
//push
template <class T>
void stack<T>::push(T data){
    stackNode<T> *temp = new stackNode<T>(data, this->top);
    this->top = temp;
}

//pop
template <class T>
T stack<T>::pop(){
    if(this->top == nullptr){
        return nullptr;
    }
    T data = this->top->getData();
    stackNode<T> *temp = this->top;
    this->top = this->top->getNext();
    delete temp;
    return data;
}

//peek
template <class T>
T stack<T>::peek(){
    if(this->top == nullptr){
        return nullptr;
    }
    return this->top->getData();
}


//isEmpty
template <class T>
bool stack<T>::isEmpty(){
    if(this->top == nullptr){
        return true;
    }
    return false;
}


//print
template <class T>
void stack<T>::print(){
    stackNode<T> *temp = this->top;
    while(temp != nullptr){
        cout << temp->getData() << endl;
        temp = temp->getNext();
    }
}
