//
// INFO 450 - Advanced Programming
// Assignment 2 - Find the Gold
// Created by Nydia Tapia
//

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

// Global variables used to declare constant variables
const int ROWS = 8;
const int COLUMNS = 8;
int guessesLeft = 5;


// Fuction 1 - Main function. In this function, I will be declaring the board four functions, methods and the 2-D array. This is also where I will be asking the user if they want to play the game again.
int main()
{
    // Declaring 4 functions and 1 method: intializing Hidden Board, printing Hidden Board, randomly placing Gold and Bomb in array, and reporting the user points. The method is dsipalying the user with the game rules and instructions.
    int initializeArray(char guessArray[ROWS][COLUMNS]);
    int printArray(char guessArray[ROWS][COLUMNS]);
    int randomArray(char guessArray[ROWS][COLUMNS]);
    int getGameRules();
    int userPoints(char guessArray[ROWS][COLUMNS]);
    
    // Declare 2-D array and variable "answer"
    char guessArray[ROWS][COLUMNS];
    char answer;
    
    //Do-while statement: The do-statement says to go through each function declared. At the end, it asks users if they want to play again? The "answer" variable is the user input asked when the game is over.
    do
    {
        initializeArray(guessArray);
        printArray(guessArray);
        randomArray(guessArray);
        getGameRules();
        userPoints(guessArray);
        
        cout << "Would you like to play again? Enter 'Y' or 'y'" << endl;
        cin >> answer;
        
        if (answer == 'y' || answer == 'Y')
        {
            guessesLeft = 5; // Reset guesses if user plays again.
        }
        
    } while (answer == 'Y' || answer == 'y');
    
    return 0;
}


// Function 2 - intializing the 'Hidden board' will intialize the guessArray. After declaraing variables, row and col, a for-loop will allow us to iterate through the array and place a "?" mark in each position. This won't print or display an array to the console.
int initializeArray(char guessArray[ROWS][COLUMNS])
{
    int row, col;
    guessesLeft = 5; // so guesses reset to 5 when array is intialized

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLUMNS; col++)
        {
            guessArray[row][col] = '?';
        }
    }
    return 0;
}


// Function 3 - Passes intializiation of the hidden board to another function allowing the array to be printed or displayed on the console.
int printArray(char guessArray[ROWS][COLUMNS])
{
    // formatting the matrix correctly after declaring variables row and col.
    int row, col;
    cout << endl;
    cout << "   ";

    for (col = 0; col < COLUMNS; col++)
    {
        cout << setw(3) << col + 1;
        // setw() sets the number of characters to be used as the field width for the next insertion operation. In this case, the length is 3 and we are displaying "col +1" at its 3rd position.  We are adding 1 to the "col" variable ("col + 1") since arrays start at 0.
    }
    cout << endl;
    cout << "  " << "--------------------------" << endl;

    for (row = 0 ; row < ROWS ; row++)
    {
        cout << " " << row + 1 << "|";
        for (col = 0; col < COLUMNS; col++)
        {
            cout << setw(3) << guessArray[row][col];
        }
        cout << endl;
    }
    cout << "  " << "--------------------------" << endl;
    return 0;
}


// Method - getGameRules - this is to explain the rules to all users in simple cout. I included  information the accepatable x,y coordinates to guess. I also included the extra credit opportunity by adding an extra guess when the user correctly guesses the coordinates of Gold.
int getGameRules()
{
    cout << "**" << "*********************" << "**" << endl;
    cout << "**" << "                     " << "**" << endl;
    cout << "**" << "   ---Find Gold---   " << "**" << endl;
    cout << "**" << "                     " << "**" << endl;
    cout << "**" << " You have 5 guesses, " << "**" << endl;
    cout << "**" << "   5 pieces of gold  " << "**" << endl;
    cout << "**" << "     and 1 bomb.     " << "**" << endl;
    cout << "**" << "                     " << "**" << endl;
    cout << "**" << "     Guess (x,y)     " << "**" << endl;
    cout << "**" << " coordinates between " << "**" << endl;
    cout << "**" << "    1 through 8.     " << "**" << endl;
    cout << "**" << "                     " << "**" << endl;
    cout << "**" << "   You will earn a   " << "**" << endl;
    cout << "**" << "   point for each    " << "**" << endl;
    cout << "**" << "   Gold you find.    " << "**" << endl;
    cout << "**" << "                     " << "**" << endl;
    cout << "**" << "    Good Luck!       " << "**" << endl;
    cout << "**" << "                     " << "**" << endl;
    cout << "**" << "   Bonus: Earn an    " << "**" << endl;
    cout << "**" << "   extra guess when  " << "**" << endl;
    cout << "**" << "   you find gold!    " << "**" << endl;
    cout << "**" << "                     " << "**" << endl;
    cout << "**" << "*********************" << "**" << endl;
    cout << endl;
    cout << endl;

    return 0;
}


// Function 4 - This is to replace the "?" marks with Gold and Bombs randomly throughout the array. Declaraing variables "x" & "y" as random and including variables tracking the bomb and Gold count.
int randomArray(char guessArray[ROWS][COLUMNS])
{
    int x, y;
    int bombCount = 0;
    int goldCount = 0;
    srand(time_t(NULL)); // This is a seed so results are random and it is tied to the clock. Esentially, the clock controls the choice of seed. Since time is always changing, the seed is forever changing too.
    
    // Do-while statement: This will add a Gold at a random (x,y) coordinate until all 5 pieces are placed throughout the array
    do
    {
        x = rand() % ROWS;
        y = rand() % COLUMNS;
        
        // If statement says to put 'G' for gold at random (x,y) coordinate
        if (guessArray[x][y] != 'G')
        {
            guessArray[x][y] = 'G';
            goldCount++;
        }
    } while (goldCount < 5); // Since the guessArray contains <= 5 Gold characters
    
    // Do-while statement: This will add a piece of 'B' at a random (x,y) coordinate
    do
    {
        x = rand() % ROWS;
        y = rand() % COLUMNS;
        
    // If statement says to put 'B' for bomb at random (x,y) coordinate
    if (guessArray[x][y] != 'G')
    {
        guessArray[x][y] = 'B';
        bombCount++;
    }
    } while (bombCount <1);
    
    return 0;
}


// Function 5 - Tallies the user points and displays if their results. The "inputRow" and "inputColumn" are user inputs and guesses they have.
int userPoints(char guessArray[ROWS][COLUMNS])
{
    int points = 0;
    int inputRow, inputColumn;

    // Do-while statement: Ask for x,y coordinates and make sure they are integers from 1 through 8. At the end, decrement the inputRow (or one of the chances). Since arrays start at 0, the user would need to guess coordinate (0,0) if they were trying to find gold at (1,1) so this is issue is fixed here.
    do
    {
        cout << "Enter x coordinate: ";
        cin >> inputRow;
        
        while (!cin || inputRow > 8 || inputRow < 1)
        {
            cout << "Please enter an integer that is between 1 and 8: ";
            cin.clear();
            cin.ignore();
            cin >> inputRow;
        }
        inputRow--;
        cout << endl;
        
        cout << "Enter y coordinate: ";
        cin >> inputColumn;
        while (!cin || inputColumn > 8 || inputColumn < 1)
        {
            cout << "Please enter an integer that is between 1 and 8: ";
            cin.clear();
            cin.ignore();
            cin >> inputColumn;
        }
        inputColumn--; // Indexes on arrays start at 0 so we must subtract 1 from the users inputs to set it at 0.
        cout << endl;

      
        // If statement: If they find gold, users will be granted an extra guess (or won't have a guess taken away from them) and they will be given a point
        if (guessArray[inputRow][inputColumn] == 'G')
        {
            cout << "You Found GOLD!! only " << guessesLeft << " guesses to go!";
            guessArray[inputRow][inputColumn] = 'F'; // Marks where user found gold at the end of the game
            points += 1;
            cout << endl;
            cout << endl;
            continue; // Go back to beginning of loop and continue
        }
        
        // Else-If they find bomb, user breaks out of loop and the game is over. They would lose the game.
        else if (guessArray[inputRow][inputColumn] == 'B')
        {
            cout << endl;
            cout << "BOMB! Game over!" << endl << endl;
            break; // breaks out of the loop
        }
        
        // Else: If user doesn't find Gold nor a bomb, they don't find anything. This doesn't help them and the user loses one guess so we would need to decrement guessesLeft by 1.
        else
        {
            cout << "Too Bad..." << endl;
            guessesLeft--;
            cout << "you have " << guessesLeft << " guesses to go!" << endl << endl;
        }
        
    } while (guessesLeft > 0); // Loop will continue until you have 0 guesses left

    
    //Message to users when broken out of the loop:
    cout << "You earned " << points << " points!" << endl;
    cout << "Better Luck Next Time" << endl;
    
    // Display array at the end where all of the gold and bombs was actually placed. Will need to take out question marks from the array and swap them with empty spaces if they are not G, B, or F.
    cout << "Here's your board:" << endl << endl;
    for (inputColumn = 0; inputColumn < COLUMNS; inputColumn++)
    {
        for (inputRow = 0; inputRow < ROWS; inputRow++)
        {
            if (guessArray[inputRow][inputColumn] == '?')
            {
                guessArray[inputRow][inputColumn] = ' ';
            }
        }
    }
    cout << "   ";

    for (inputColumn = 0; inputColumn < COLUMNS; inputColumn++)
    {
        cout << setw(3) << inputColumn + 1;
    }
    cout << endl;
    cout << "  " << "--------------------------" << endl;

    for (inputRow = 0; inputRow < ROWS; inputRow++)
    {
        cout << " " << inputRow + 1 << "|";
        for (inputColumn = 0; inputColumn < COLUMNS; inputColumn++)
        {
            cout << setw(3) << guessArray[inputRow][inputColumn];
        }
        cout << endl;
    }

    cout << "  " << "--------------------------" << endl;
    return 0;
}
