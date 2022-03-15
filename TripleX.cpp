#include<iostream>
#include<ctime>

void PrintIntroduction(int Difficulty)
{
    //prints Intro to terminal
    std::cout << "\n\n You are an explorer traveling the far reaches of the universe.\n";
    std::cout << "Unfortunately you've caught the attention of some level " << Difficulty << " space pirates.\n";
    std::cout<< "You must Enter the correct codes to access your hyper-drive and jump to a new galaxy...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // declace 3 number code 
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    // Stores and prints the CodeSum and CodeProduct
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << "There are three numbers in the code.";
    std::cout << "\n The codes add-up to: " << CodeSum;
    std::cout <<"\n The codes multiply to give: " << CodeProduct << std::endl;

    //storing player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Guess if plyers guess is correct
    if(CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "*** Great job Captain you've made it to the next galaxy keep going ***\n";
        return true;
    }
    else
    {
        std::cout << "*** Sorry you failed to outrun the pirates ***\n!";
        std::cout << "*** Would you like to retry the level? ***";
        return false;
    }

}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty) // will loop game until all levels are complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) 
        {
            // increase level difficulty
            ++LevelDifficulty;

        }
    }

    std::cout <<"\n*** Congratulations Captain you've outrun all the pirates! Now go explore undiscovered worlds! ***\n";
    return 0;
}