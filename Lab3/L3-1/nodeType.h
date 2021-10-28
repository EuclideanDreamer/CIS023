//nodeType.h 
#ifndef H_nodeType
#define H_nodeType
template <class Type>
class nodeType{
public:
	Type info;
	nodeType<Type> *link;

	//getter n setter
	Type getInfo();
	void setInfo(const Type&);
};

template<class Type>
Type nodeType<Type>::getInfo(){
	return info;
}

template<class Type>
void nodeType<Type>::setInfo(const Type& item){
	info = item;
}
#endif 