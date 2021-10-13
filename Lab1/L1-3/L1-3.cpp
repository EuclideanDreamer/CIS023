//Exicutable file
class Test
{
private:
    ch3sortTest run;
    void shortLine();
    void longLine();
public:
    Test(){}
    ~Test(){}
    void demoRandom();//demonstrate how long it takes for random 
    void demoAcending();
    void demoDecending();
};

void Test::shortLine(){
    cout<<"*-------------------------------------------*"<<std::endl;
}
void Test::longLine(){
    cout<<"*-----------------------------------------------------------------------------*"<<std::endl;
}
void Test::demoRandom(){
    cout <<"Loading Inital Array :"<<endl;
    clock_t time = clock();
    run.setArray();
    time = run.getTime(time);
    cout << "Processing 10000 elemnts\nwith random values took"<<endl;
    cout << time << " Microseconds"<<endl; longLine();
    //----------------------------------------------------
    shortLine(); cout << "* Testing - sorts with Random array values *" << endl; shortLine();
    cout << "Bubble Sort array :"<<endl;   
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.bubbleSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Bubble Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
    //--------------------------------------------------------
    cout << "Insertion Sort array :"<<endl;    run.setArray();
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.insertionSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Insertion Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
    //--------------------------------------------------------
    cout << "Selection Sort array :"<<endl;     run.setArray();
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.selectionSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Selection Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
}
void Test::demoAcending(){
    
    cout <<"Loading Inital Array :"<<endl;
    clock_t time = clock();
    run.setAsendArray();
    time = run.getTime(time);
    cout << "Processing 10000 elemnts\nwith ascending caues took"<<endl;
    cout << time << " Microseconds"<<endl; longLine();
    //----------------------------------------------------
    shortLine(); cout << "* Testing - sorts with Ascending array values *" << endl; shortLine();
    cout << "Bubble Sort array :"<<endl;   
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.bubbleSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Bubble Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
    //--------------------------------------------------------
    cout << "Insertion Sort array :"<<endl;    run.setAsendArray();
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.insertionSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Insertion Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
    //--------------------------------------------------------
    cout << "Selection Sort array :"<<endl;     run.setAsendArray();
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.selectionSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Selection Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;

}
void Test::demoDecending(){
    cout <<"Loading Inital Array :"<<endl;
    clock_t time = clock();
    run.setDesndArray();
    time = run.getTime(time);
    cout << "Processing 10000 elemnts\nwith descending values took"<<endl;
    cout << time << " Microseconds"<<endl; longLine();
    //----------------------------------------------------
    shortLine(); cout << "* Testing - sorts with Descending array values *" << endl; shortLine();
    cout << "Bubble Sort array :"<<endl;   
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.bubbleSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Bubble Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
    //--------------------------------------------------------
    cout << "Insertion Sort array :"<<endl;    run.setDesndArray();
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.insertionSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Insertion Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
    //--------------------------------------------------------
    cout << "Selection Sort array :"<<endl;     run.setDesndArray();
    cout << "       Before Sort: "; run.printEleven();
    time= clock(); run.selectionSort(); time =run.getTime(time);
    cout << "         After Sort: "; run.printEleven();
    cout <<"Processing 10000 Elements\nwith Selection Sort took\n"<<time<< " microseconds"<<endl;
    longLine();
    cout <<endl;    cout <<endl;
}
int main(){
    std::cout << “Bailey Nichols\t“ << “L 1-3\t“ << “L1-3.exe“ << std::endl;
    Test T;
    //
    T.demoRandom();//demonstrates random array and sorting
    //--------------------------------------------------
    T.demoAcending();//demonstrates random array and sorting
    //----------------------------------------------------
    T.demoDecending();//demonstrates random array and sorting
    return 0;
}
