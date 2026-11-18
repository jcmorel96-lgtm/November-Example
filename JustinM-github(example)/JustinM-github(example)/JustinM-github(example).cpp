// JustinM-github(example).cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>

#include <vector>
#include <ctime>

#include <cstdlib>
#include <fstream>

#include <thread>
#include <chrono>



/*
    //Randomization//
        
    //Changing Colors//

    //Fill ins//
look up lava lamp random clock...

*/

// method //

int GenerateRandomNumber(int min, int max)
{
    int randomNumber = 0;

    std::srand(std::time(0)); // generates a random seed based on system clock // 

    // to actually generate a random number // 

    randomNumber = (std::rand() % max) + min;

    return randomNumber;
}

void WriteToFile(std::string fileName)
{
    std::ofstream file(fileName); // this could look like "readme.txt" if we were hardcoding and not using the parameter
        // this works even if the file doesn't exist it will create it
        // this will also completely overwrite anything that was in the file previously
        // with no prompt to save as or are you sure

        if (file.is_open())
        {
            // we can write to it
            file << "this is our first time writing to a file" << std::endl;
            file << "our second line" << std::endl;

            // we need to close any file we open
            file.close();
        }
        else
        {
            // otherwise it did open
            std::cout << "file found not be opened" << std::endl;
        }
}

void ReadFromFile(std::string fileName)
{
    std::ifstream file(fileName); // like WriteToFile we could put any string here that represents a file name
    // i.e "readme.txt"


    //file.open();

    std::string line = "";

    while (getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
}


int main()
{
    std::cout << "Hello World!\n";

    int newNumber = GenerateRandomNumber(1, 10); // intializes int "newNumber" and assigns the GenerateRandomNumber method with parameters for min and max //

    std::cin.get();

    int bigNumber = GenerateRandomNumber(1, 1000);

    std::cout << "newNumber: " << newNumber << std::endl;
    std::cout << "bigNumber: " << bigNumber << std::endl;

    WriteToFile("thiswasnttherebefore.txt");

    std::this_thread::sleep_for(std::chrono::seconds(5)); // this stops the project from running for 5 seconds

    ReadFromFile("thiswasnttherebefore.txt");

    std::cout << "\033[31mWARNING!! \033[0m" << std::endl;
    std::cout << "\033[92mSuccess! \033[0m" << std::endl;

    std::string words = "Mission Start";

    for (int i = 0; i < words.size(); i++)
    {
        std::cout << words[i] << std::endl; // remove escape character or std::endl; to see output sideways.
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
