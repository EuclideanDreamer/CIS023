#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string line;
    std::ifstream myfile("infixData.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            for (int i = 0; i < line.length; i++)
            {
                char c = line[i];
            }
            
        }
        myfile.close();
    }
    else std::cout << "Unable to open file";
    return 0;
}