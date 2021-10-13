#include "die.h"

die::die(){
    num=1;
}

void die::roll(){
    num=rand() % 6 +1;
}

int die::getNum() const{
    return num;
}
int main(){
    //first exe
    std::cout << “Bailey Nichols\t“ << “L 1-1\t“ << “L1-1.exe“ << std::endl; 
    std::cout << "Enter the number of dies to use (4, 5, or 6)\nor press enter to default to 6 ";
    int dieNumber; std::string dieNumberStr;//making string to read input and number to use for processing
    if (std::getline(std::cin, dieNumberStr)){ //using getline with if to read input with only \n 
        if (dieNumberStr.empty()){ //using std::string.empty() Stroustrup pg898
            dieNumber=6;
        }else if (dieNumberStr=="5"){
            dieNumber=5;
        }else if (dieNumberStr=="4"){
            dieNumber=4;
        }else if (dieNumberStr=="6"){
            dieNumber=6;
        }else{
            dieNumber=6;
        }
    }
    std::cout<<std::endl;
    std::cout<< "Enter the number of times the "<<dieNumber<< std::endl;
    std::cout<< "dice are to be rolled (2500, 3000 or 5000)\nor press enter to default to 5000 ";
    //
    int numTimes =5000; std::string numTimeStr;
    if (std::getline(std::cin, numTimeStr)){
        if (numTimeStr=="2500"){
            numTimes=2500;
        }if (numTimeStr=="3000"){
            numTimes=3000;
        }if (numTimeStr=="5000"){
            numTimes=5000;
        }
    }
    char star='*';//to be used to make graph
    int array[numTimes];//array to store values 
    int sum=0;//init sum to zero to stop undefined behevior 
    int starnumber;//another int needed to store value for printing stars
    //
    for (int i=0; i<numTimes; i++){
        array[i]=0;//init array to zero to stop undefined behevior 
    }
    //
    for (int i=0; i<numTimes; i++){//first loop
    // 
        for (int j =0; j<dieNumber; j++){//second loop
            die dice;//init dice obj
            dice.roll();//see die.h
            sum += dice.getNum();
        }//end loop 2
        //
        array[sum] += 1;//add one to each position in array to count sums 
        sum=0;//reset sum to 0
    }//end loop 1
    //
    int graphlimit, highestNum{0}, percent; //int for limiting graph and one to hold highest value in arr, and one to hold the 
    if (dieNumber==4){                      //value of 2% of the highest value
        graphlimit=25;
    }else{
        graphlimit=37;
    }
    for(int i=0; i<numTimes; i++){//find higest number in the array. 
        if (highestNum<array[i]){
            highestNum=array[i];
        }
    }
    percent=highestNum*0.02;
    //code below for gaph syntax was donated by Professor John Urrutia 
    //thx to prof
    std::cout <<"For "<<dieNumber<<" dice, rolled "<<numTimes<<" times"<< std::endl;
    std::cout <<"Count %:---   0    10   20   30   40   50   60   70   80   90   100"<< std::endl;
    std::cout <<"Sum    count  |....|....|....|....|....|....|....|....|....|....|"<< std::endl;
    for (int i = 0; i < graphlimit; i++)// no need to go all the way to 5000
    {
        std::cout <<" "  << std::setw(2) <<i;          // Formatting so Sum and count columns
        std::cout <<"  ("<< std::setw(4) <<array[i]<<")   "; // are neat and tidy
        starnumber=array[i]/percent;// number of stars = (value / (highestValue * 0.02))
        //
        for (int j=0; j<starnumber; j++){//loop to multiply char by int
            std::cout<<star;
        }
        std::cout<<std::endl;
    }
    //code told to insert just before 'return 0'
    char q;
    std::cout << "\nPress any key to Exit.";
    std::cin.ignore(2, '\n');
    std::cin.get(q);
    return 0;
}
