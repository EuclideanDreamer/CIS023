#include <iostream>
#include <string>
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
using namespace std;

int main(){
    orderedLinkedList<int> list1;
    orderedLinkedList<string> list2;

    unorderedLinkedList<int> list3;
    unorderedLinkedList<string> list4;

    list1.initializeList();
    list1.isEmptyList();
    list1.print();
    list1.length();
    list1.destroyList();
    list1.insertFirst(123);
    list1.front();
    list1.back();
    list1.insertLast(456);
    list1.deleteNode(123);
    list1.search(123);

    nodeType<float> node1;
    node1.getInfo();
    node1.setInfo(123.0);
    node1 = node1;

    return 0;
}