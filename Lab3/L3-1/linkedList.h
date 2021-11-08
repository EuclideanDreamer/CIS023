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
'* 06/06/12      Nichols 000.000.000 Initial release of program       * 
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
protected://why? why shouldn't it be 'public'
	int count;// ie length
	nodeType<Type> *first;//pointer to first node
	nodeType<Type> *last;//pointer to last
};
//
#endif
