#include <iostream>
#include <random>

int main()
{
    bool playing = true;
    int wins = 0;
    int loses = 0;
    int ties = 0;

    do
    {
        char choices[4] = { 'r', 'p', 's', 'x' };
        char playerChoice;
        char cpuChoice;
        int cpuInput;
        bool invalidInput = true;

        do
        {
            std::cout << "Enter your move [r, p, s] or type 'x' to end the game: ";
            std::cin >> playerChoice;

            for (int i = 4 - 1; i >= 0; i--)
            {
                if (playerChoice == choices[i])
                {
                    invalidInput = false;
                    break;
                }
            }

        } while (invalidInput);
        

        if (playerChoice == 'x')
        {
            playing = false;
            break;
        }

        srand(time(0));
        cpuInput = rand() % 3;
        cpuChoice = choices[cpuInput];

        if (playerChoice == cpuChoice)
        {
            std::cout << "Tie";
            ties++;
        }
        else
        {
            if (playerChoice == 'r' && cpuChoice == 's' || playerChoice == 'p' && cpuChoice == 'r' || playerChoice == 's' && cpuChoice == 'p')
            {
                std::cout << "You Win!";
                wins++;
            }
            else
            {
                std::cout << "You Lose :(";
                loses++;
            }
        }
    
        std::cout << "\nPlayer: " << playerChoice << " | CPU: " << cpuChoice << "\nWins: " << wins << " | Loses: " << loses << " | Ties: " << ties << "\n\n";
    }
    while (playing);

    return 0;
}