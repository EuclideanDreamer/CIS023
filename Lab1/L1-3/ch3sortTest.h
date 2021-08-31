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
            if (array[j] > array[i]){ // if a > b 
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                temp=0;
            }
        }
    }
}
void ch3sortTest::selectionSort(){
    int min, temp{0};
    for (int i = 0; i < ARRAY_SIZE; i++){
        min=i;
        for (int j = 0; j < ARRAY_SIZE; j++){
            if (array[i]<array[j]){
                min=1;
            }
        }
        temp = array[i]; 
        array[i] = array[min];
        array[min]=array[temp];

        temp=0;
    }
}
void ch3sortTest::insertionSort(){
    int key{0}, j{0};//J is made here with a key, //key is what will be inserted
    for (int i = 1; i < ARRAY_SIZE; i++){
        key=array[i];
        j=i-1;
        while ((key<array[j])&&(j>=0)){
            array[i]=array[j]; --j;
        }
        array[i]=key;
    }
}
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
    for (int i = 0; i < 11; i++)
    {
        cout << " "<<array[i];
    }
    cout <<endl;
}