#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
#define ARRAY_SIZE 10000
using namespace std;
class ch3sortTest
{
private:
    /* data */
    int array[ARRAY_SIZE];
public:
    ch3sortTest(/* args */);
    ~ch3sortTest();
    clock_t getTime(clock_t inTime);
    void setArray();
    void setAsendArray();
    void setDesndArray();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void sortArraySTD(); //why not use 'std::sort()' page 109: Sroustrup "The C++ Programming Language"
    void printEleven();
};

ch3sortTest::ch3sortTest(){
    for (int i=0; i<ARRAY_SIZE; i++){
        array[i]=0;
    }
}
//
ch3sortTest::~ch3sortTest(){}
//
void ch3sortTest::bubbleSort(){
    int temp{0};//assign temporary as zero 
    for (int i =0; i<ARRAY_SIZE; i++){ //loop 1
        for (int j = 0; j < ARRAY_SIZE; j++){ //loop 2
            if (array[j] > array[i]){ // if b > a 
                temp = array[i];      // swap a and b using temp
                array[i] = array[j];  // 
                array[j] = temp;
                temp=0;
            }//bubble sort is easy. 
        }//Donald Knuth. The Art of Computer Programming, 
    }    //Volume 3: Sorting and Searching, Second Edition. 
}        //Addison-Wesley, 1998. ISBN 0-201-89685-0. Pages 106–110
void ch3sortTest::selectionSort(){
    int min{0}, temp{0}; //init minimum to hold index value of min, and temporary intiger for swap
    for (int i = 0; i < ARRAY_SIZE-1; i++){// Loop 1 //to close range of unsorted array as array is sorted
        min = i;//minimum element 
        for (int j = i+1; j < ARRAY_SIZE; j++){//loop 2// find unsorted int and make min that index value
            if (array[j] < array[min]){ //if unsorted 
                min = j; //assign min as index j
            }
        }
        if(min!=i){
            temp= array[i];//swap i and min
            array[i]=array[min];
            array[min] =temp;
        }//thanks to wikipedia for code
    }    //https://en.wikipedia.org/wiki/Selection_sort 
}
void ch3sortTest::insertionSort(){
    int key, j; //init key to sort with and j for while loop
    for (int i = 1; i < ARRAY_SIZE; i++){//start at 1
        key=array[i]; j=i-1;//begin at the beginning
        while ((j>=0)&&(array[j]>key)){//sort against key
            array[j+1]=array[j];//step down all elements
            --j;
        }
        array[j+1]=key;//swap unsorted location for found key
    }//thanks to Wikipedia for sudocode 
}    //https://en.wikipedia.org/wiki/Insertion_sort 
clock_t ch3sortTest::getTime(clock_t inTime){
    return abs(inTime - clock());
}
//
void ch3sortTest::setArray(){
    for (int i=0; i<ARRAY_SIZE; i++){
        array[i]=rand();
    }
}
//
void ch3sortTest::setAsendArray(){
    for (int i=0; i<ARRAY_SIZE; i++){
        
        array[i]=i;
    }
}
//
void ch3sortTest::setDesndArray(){
int j{10000};
    for (int i=0; ARRAY_SIZE>i; i++){
        --j;
        array[i]=j;
    }
}
//
void ch3sortTest::sortArraySTD(){
    int front= sizeof(array) / sizeof(array[0]);
    sort(array, array+front);
}
//
void ch3sortTest::printEleven(){
    for (int i = 0; i < 15; i++)
    {
        cout << " "<<array[i];
    }
    cout <<endl;
}