/*
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Header Name   :       nodeType.h                  * 
'*                                                                     * 
'* Written by      : Bailey Nichols                      * 
'*                                                                     * 
'* Purpose         :          This is a node in memory            * 
'*                                                                     * 
'* Inputs          :    accepts template<info>  as private member
'*                                                                     * 
'* Calls           :   Calls pointer to other nodeType
'*                                                                     * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 11/06/12      Nichols 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
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
