#include "die.h"
int main(){
    //first exe
    std::cout << "Enter the number of dies to use (4, 5, or 6)\nor press enter to default to 6 ";
    int dieNumber = std::cin.get(); //using cin.get so the console will read the newline from Enter key
    switch (dieNumber)//cheap and easy error checking
    {
    case '4':
        dieNumber=4;
        break;
    case '5':
        dieNumber=5;
        break;
    case '6':
        dieNumber=6;
        break;
    default:
    dieNumber=6;
        break;
    }
    std::cout<<std::endl;
    std::cout<< "Enter the number of times the "<<dieNumber<< std::endl;
    std::cout<< "dice are to be rolled (2500, 3000 or 5000)\nor press enter to default to 5000";
    //
    int numTimes = std::cin.get();//repeat of structure above
    
    switch (numTimes)
    {
    case 2500:
        numTimes=2500;
        break;
    case 3000:
        numTimes=3000;
        break;
    case 5000:
        numTimes=5000;
        break;
    
    default:
        numTimes=5000;
        break;
    }
    //
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
    //code below for gaph syntax was donated by Professor John Urrutia 
    //thx to prof
    std::cout <<"For "<<dieNumber<<" dice, rolled "<<numTimes<<" times"<< std::endl;
    std::cout <<"Count %:---   0    10   20   30   40   50   60   70   80   90   100"<< std::endl;
    std::cout <<"Sum    count  |....|....|....|....|....|....|....|....|....|....|"<< std::endl;
    for (int i = dieNumber; i < 37; i++)// no need to go all the way to 5000
    {
        std::cout <<" "  << std::setw(2) <<i;          // Formatting so Sum and count columns
        std::cout <<"  ("<< std::setw(4) <<array[i]<<")   "; // are neat and tidy
        starnumber=array[i]/10;// upper limit = approx 500 ergo,  x/50 = starNumber if *=2... see notes 
        //
        for (int j=0; j<starnumber; j++){//loop to cheat and multiply char by int
            std::cout<<star;
        }
        std::cout<<std::endl;
    }
    
    
}