// This is the code for A Sudoku Game using concepts of 2D Arrays, loops, functions and recursion
#include<iostream>
#include<ctime>
#include<cstdlib>
//The following 2 libraries are for the delay function
#include <thread>
#include <chrono>
using namespace std;

//FUNCTION 9
void delay(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

//FUNCTION 2
// Dynamic printBoard function for any size (3, 6, 9)
void printBoard(int board[9][9], int size) {
    int boxSize = (size == 9) ? 3 : (size == 6 ? 2 : 1);
    cout << "\nCurrent Sudoku Board:\n";

    for (int i = 0; i < size; i++) {
        // Print horizontal separator every boxSize rows
        if (i % boxSize == 0) {
            cout << "+";
            for (int k = 0; k < size; k++) {
                cout << "---"; // three dashes for better alignment
                if ((k + 1) % boxSize == 0) cout << "+";
            }
            cout << "\n";
        }

        // Print each row
        for (int j = 0; j < size; j++) {
            if (j % boxSize == 0) cout << "|";
            if (board[i][j] == 0)
                cout << "   "; // empty cell: 3 spaces
            else
                cout << " " << board[i][j] << " "; // number centered
        }
        cout << "|\n";
    }

    // Print bottom border
    cout << "+";
    for (int k = 0; k < size; k++) {
        cout << "---";
        if ((k + 1) % boxSize == 0) cout << "+";
    }
    cout << "\n";
}


//FUNCTION-1
bool IsTheMoveValid(int array[9][9], int rows, int columns, int input, int size) {

    //Check the entire row
    bool IsInThisRow[10] = { false }; // Boolean array to track numbers in the row
    for (int j = 0; j < size; j++) {
        int CurrentCellValue = array[rows][j]; // Value in the current cell of the row
        if (CurrentCellValue != 0) { // Ignore empty cells
            if (IsInThisRow[CurrentCellValue]) {
                // If this number already appeared in the row, move is invalid
                return false;
            }
            else {
                // Mark this number as seen
                IsInThisRow[CurrentCellValue] = true;
            }
        }
    }

    // Check the entire column

    bool IsInThisColumn[10] = { false }; // Boolean array to track numbers in the column
    for (int i = 0; i < size; i++) {
        int CurrentCellValue = array[i][columns]; // Value in the current cell of the column
        if (CurrentCellValue != 0) {
            if (IsInThisColumn[CurrentCellValue]) {
                // If this number already appeared in the column, move is invalid
                return false;
            }
            else {
                IsInThisColumn[CurrentCellValue] = true;
            }
        }
    }
    // Determine subgrid size

    int boxSize;
    if (size == 9) {
        boxSize = 3; // For 9x9 Sudoku, subgrid is 3x3
    }
    else if (size == 6) {
        boxSize = 2; // For 6x6 Sudoku, subgrid is 2x2
    }
    else {
        boxSize = 1; // For 3x3 Sudoku, subgrid is 1x1
    }

    //Check the subgrid
    bool IsInThisGrid[10] = { false }; // Boolean array to track numbers in the subgrid
    int StartingRowOfBox = (rows / boxSize) * boxSize; // Top-left row of the subgrid
    int StartingColOfBox = (columns / boxSize) * boxSize; // Top-left column of the subgrid

    for (int i = StartingRowOfBox; i < StartingRowOfBox + boxSize; i++) {
        for (int j = StartingColOfBox; j < StartingColOfBox + boxSize; j++) {
            int CurrentCellValue = array[i][j];
            if (CurrentCellValue != 0) {
                if (IsInThisGrid[CurrentCellValue]) {
                    // If this number already appeared in the subgrid, move is invalid
                    return false;
                }
                else {
                    IsInThisGrid[CurrentCellValue] = true;
                }
            }
        }
    }
    if (IsInThisRow[input] || IsInThisColumn[input] || IsInThisGrid[input]) {
        // If the input number already exists in row, column, or subgrid then its invalid
        return false;
    }
    else {
        // Otherwise, move is valid
        return true;
    }
}

//FUNCTION-3
void generateBoard(int arr[9][9], int size, int row = 0) {
    //I changed all of the hardcoded 9s to size to give user an option of size selection
    if (row == size) {
        return;
    }
    else {
        for (int j = 0; j < size; j++) {
            bool placed = false;
            for (int pass = 0; pass < size; pass++) {
                int num = rand() % size + 1;
                if (IsTheMoveValid(arr, row, j, num, size)) {
                    arr[row][j] = num;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                for (int k = 0; k < size; k++) {
                    arr[row][k] = 0;
                }
                generateBoard(arr, size, row);
                return;
            }
        }
        generateBoard(arr, size, row + 1);
    }
}

//FUNCTION-4
// Remove cells based on difficulty
void removeCells(int board[9][9], int size, string difficulty) {
    int totalCells = size * size;
    int removeCount;
    if (difficulty == "easy") {
        removeCount = totalCells * 0.3;
    }
    else if (difficulty == "medium") {
        removeCount = totalCells * 0.5;
    }
    else {
        removeCount = totalCells * 0.7;
    }

    for (int i = 0; i < removeCount; i++) {
        int r = rand() % size;
        int c = rand() % size;
        board[r][c] = 0;
    }
}

//FUNCTION 5
bool solver(int board[9][9],int size,int row =0){
    if(row==size){
        return true;
    }
        for (int col = 0; col < size; col++) {
            if (board[row][col]==0) { // Checks for empty cell, solver will only fill them
                for(int num =1;num<=size;num++){
                    if (IsTheMoveValid(board, row, col, num,size)) {
                        board[row][col] = num;
                        if (solver(board,size)) return true;
                        board[row][col] = 0; // If the board isn't solvable after inputting a certain number at a cell, we will make it zero and try again (num has incremented by 1)
                    }
                }
                return false; 
            }
        }
    return solver(board,size,row+1); // all cells filled
}

//FUNCTION-6
// Generate random hints
void hint(int arr[9][9], int size) {
    int num;
    int row = rand() % size;
    int col = rand() % size;
    if (arr[row][col] == 0) {
        int temp[9][9];
        for(int i =0;i<size;i++){
            for(int j=0;j<size;j++){
                temp[i][j]=arr[i][j];
            }
        }
        if(solver(temp,size)){
            int num=temp[row][col];
             cout << num << " will be at row # " << row + 1 << " at column # " << col + 1 << endl;
             arr[row][col] = num;
            return;
            }
            else{
                cout << "No hints available at the current arrangement of numbers.\n";
                return;
            }
        }
    // Calling the function again (recursion) if the row is already filled or the hint isn't valid.
    hint(arr, size);
}

//FUNCTION 7
bool checker(int arr[9][9],int size){
    for(int row =0;row<size;row++){
        for(int col=0;col<size;col++){
            bool correct = false;
            int num = arr[row][col];
            if (num==0){
                continue;
            }
            arr[row][col]=0;
            if(IsTheMoveValid(arr,row,col,num,size)){
                correct = true;
            }else{
                cout << "The board is not valid according to sudoku rules\n";
                return false;
            }
        }
    }
    return true;
}

//FUNCTION 8
void Game_Menu(){
    cout << "\n__________MENU__________\n";
    cout << "1. Make a Move\n";
    cout << "2. Get a Hint (-10 points)\n";
    cout << "3. Request a fully solved board (This Ends The Game)\n";
    cout << "4. Check Board\n";
    cout << "5. Quit\n";
    cout << "Enter your choice: ";
}

int main() {
    //for our random factor
    srand(time(0));
    //Displaying the welcome msg
    //This will get displayed only once at the start of each game.That's it.

    cout << "\n_________Welcome to the Sudoku Game_________\n";
    int size;
    do {
        cout << "Choose grid size (3, 6, or 9): ";
        cin >> size;
        if (size != 3 && size != 6 && size != 9) {
            cout << "Invalid size! Enter a valid grid size! \n";
        }
    } while (size != 3 && size != 6 && size != 9);
    delay(1);

    //Difficulty Level
    cout << "Choose the Difficulty Level (easy, medium, hard): ";
    string difficulty;
    cin >> difficulty;
    cout << "Please wait\n"; 
    cout << "Loading your game...\n";
    delay(2);

    //Rules
    cout << "___________________________________________Rules___________________________________________\n";
    cout << "--> Enter row, column, and value (1-9).\n";
    cout << "--> You have to fill appropriate numbers in the empty cells.\n";
    cout << "--> A number you choose for a cell must be unique in that row,column as well as the subgrid.\n";
    cout << "--> Enter # to get a hint.\n";
    cout << "[Requesting a hint will result in score deduction! (-10 for each)]\n";
    cout << "--> Type 0 0 0 to quit.\n\n";
    delay(5);

    int row, column, value;
    //starting with an empty board for declaration purposes
    int array[9][9] = { };

    // Generating a random board using our function
    generateBoard(array, size, 0);

    // Remove cells based on difficulty
    removeCells(array, size, difficulty);

    // Printing the initial board that has been generated using our random function
    printBoard(array, size);

    //Doing the scoring implementaion.
    //Starting with a full score of 100
    //Loop runs until game is over
    //Gameover is a bool that is false in the beginning, this loop will break as soon as it becomes true
    
    int score = 100;        // Starting score
    int mistakes = 0;       // Mistake counter
    int maxMistakes = 5;    // Maximum allowed mistakes
    bool gameOver = false;  // Flag to control game loop

    while (!gameOver) {
        //I'll display user the controls on each attempt so that he can choose what he wants to do
        Game_Menu();
        //As the upper function gets executed, I'll store the user's input into this variable and make my switch using that 
        int choice;
        
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter The Row #: ";
            cin >> row;
            cout << "Enter The Column #: ";
            cin >> column;
            cout << "Enter The Value: ";
            cin >> value;

            //Checking if user wants to quit
            if (row == 0 && column == 0 && value == 0) {
                cout << "Exiting the game. Thanks for playing!\n";
                gameOver = true;
                break; 
            }
            //If not, then check for correct or incorrect input
            if (row >= 1 && row <= size && column >= 1 && column <= size && value >= 1 && value <= size) {
                if (IsTheMoveValid(array, row - 1, column - 1, value, size)) {
                    array[row - 1][column - 1] = value;
                    printBoard(array, size);
                }
                else {
                    cout << "Invalid move! That number conflicts with Sudoku rules.\n";
                    mistakes+=1;
                    score -= 15; // Deduct points for mistake
                }
            }
            else {
                cout << "Invalid input! Please enter numbers ranging from 1 to 9.\n";
                continue;
            }
            break;

        case 2:
        //If hint was requested
            {
                if (score >= 10) {
                hint(array, size);
                printBoard(array, size);
                score -= 10; // Deduct points for hint
            } 

            else {
                cout << "You don't have enough score to request a hint!\n";
            }
            break;
        }
           case 3: 
            //If Solved Board was requested
           {
            solver(array, size);
            printBoard(array, size);
            cout << "You requested the solved Board. You lose!\n";
            cout<<"__________________Game Over__________________\n";
            gameOver = true;
            break;
        }

           case 4:
            // Check Board
            {
            if (checker(array, size)) {
                cout << "Board is valid!\n";
            } else {
                cout << "Board is invalid!\n";
            }
            break;
        }

        case 5: 
        //For simply quitting the game.
        {
             cout << "You are now exiting the game....\n";
            cout << "Thanks for playing!\n";
            gameOver = true;
            break;
        }

        default:
            cout << "Invalid choice!\n";
      
        }   //this brace ends the switch

         // Show score and mistakes after each action
         cout << "Score: " << score << " | Mistakes: " << mistakes << "/" << maxMistakes << "\n";

        // Check losing conditions
        if (mistakes > maxMistakes || score <= 0) {
            cout << "Game Over! You lost.\n";
            gameOver = true;

        }


    }       //this brace ends the while loop of game
    return 0;
}            //this brace ends the main 

