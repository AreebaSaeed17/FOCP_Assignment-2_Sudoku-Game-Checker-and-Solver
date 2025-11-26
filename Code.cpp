#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std; 

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
                cout << "-" << "-"; // two dashes per cell for spacing
                if ((k + 1) % boxSize == 0) cout << "+";
            }
            cout << "\n";
        }

        // Print each row
        for (int j = 0; j < size; j++) {
            if (j % boxSize == 0) cout << "|";
            if (board[i][j] == 0)
                cout << " "; // empty cell as dot
            else
                cout << " " << board[i][j];
        }
        cout << "|\n";
    }

    // Print bottom border
    cout << "+";
    for (int k = 0; k < size; k++) {
        cout << "-" << "-";
        if ((k + 1) % boxSize == 0) cout << "+";
    }
    cout << "\n";
}



//FUNCTION-1
bool IsTheMoveValid(int array[9][9], int rows, int columns, int input, int size) {

    //Check the entire row
    bool IsInThisRow[10] = {false}; // Boolean array to track numbers in the row
    for (int j = 0; j < size; j++) {
        int CurrentCellValue = array[rows][j]; // Value in the current cell of the row
        if (CurrentCellValue != 0) { // Ignore empty cells
            if (IsInThisRow[CurrentCellValue]) {
                // If this number already appeared in the row, move is invalid
                return false;
            } else {
                // Mark this number as seen
                IsInThisRow[CurrentCellValue] = true;
            }
        }
    }

    // Check the entire column
  
    bool IsInThisColumn[10] = {false}; // Boolean array to track numbers in the column
    for (int i = 0; i < size; i++) {
        int CurrentCellValue = array[i][columns]; // Value in the current cell of the column
        if (CurrentCellValue != 0) {
            if (IsInThisColumn[CurrentCellValue]) {
                // If this number already appeared in the column, move is invalid
                return false;
            } else {
                IsInThisColumn[CurrentCellValue] = true;
            }
        }
    }
    // Determine subgrid size

    int boxSize;
    if (size == 9) {
        boxSize = 3; // For 9x9 Sudoku, subgrid is 3x3
    } else if (size == 6) {
        boxSize = 2; // For 6x6 Sudoku, subgrid is 2x2
    } else {
        boxSize = 1; // For 3x3 Sudoku, subgrid is 1x1
    }

    
    //Check the subgrid
    bool IsInThisGrid[10] = {false}; // Boolean array to track numbers in the subgrid
    int StartingRowOfBox = (rows / boxSize) * boxSize; // Top-left row of the subgrid
    int StartingColOfBox = (columns / boxSize) * boxSize; // Top-left column of the subgrid

    for (int i = StartingRowOfBox; i < StartingRowOfBox + boxSize; i++) {
        for (int j = StartingColOfBox; j < StartingColOfBox + boxSize; j++) {
            int CurrentCellValue = array[i][j];
            if (CurrentCellValue != 0) {
                if (IsInThisGrid[CurrentCellValue]) {
                    // If this number already appeared in the subgrid, move is invalid
                    return false;
                } else {
                    IsInThisGrid[CurrentCellValue] = true;
                }
            }
        }
    }
    if (IsInThisRow[input] || IsInThisColumn[input] || IsInThisGrid[input]) {
        // If the input number already exists in row, column, or subgrid then its invalid
        return false;
    } else {
        // Otherwise, move is valid
        return true;
    }
}

//Function to generate the board

void generateBoard(int arr[9][9], int size, int row = 0) {
    //I changed all of the hardcoded 9s to size to give user an option of size selection
    if (row == size) {
        return; 
    } else {
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


// Remove cells based on difficulty
void removeCells(int board[9][9], int size, string difficulty) {
    int totalCells = size * size;
    int removeCount;
    if (difficulty == "easy") {
        removeCount = totalCells * 0.3;}
    else if (difficulty == "medium") {
        removeCount = totalCells * 0.5;}
    else {
        removeCount = totalCells * 0.7;}

    for (int i = 0; i < removeCount; i++) {
        int r = rand() % size;
        int c = rand() % size;
        board[r][c] = 0;
    }
}



int main(){
    //for our random factor
    srand(time(0));
    //Displaying the welcome msg
    cout<<"_________Welcome to the Sudoku Game_________\n";
    int size;
    do{
    cout << "Choose grid size (3, 6, or 9): ";
    cin >> size;
    if (size != 3 && size != 6 && size != 9) {
        cout << "Invalid size! Enter a valid grid size! \n";
    }
    } while(size != 3 && size != 6 && size != 9);

    //Difficulty Level
    cout << "Choose the Level difficulty (easy, medium, hard): ";
    string difficulty;
    cin >> difficulty;

    //Rules
    cout << "Rules:\n";
    cout<<"--> Enter row, column, and value (1-9).\n";
    cout<<"--> 0 means empty cell.\n";
    cout<<"--> Enter # to get a hint.\n";
    cout<<"[Requesting a hint will result in score deduction! (-10 for each)]\n";
    cout<<"--> Type 0 0 0 to quit.\n\n";

    int row, column, value;
    //starting with an empty board for declaration purposes
    int array[9][9] = { };

    // Generating a random board using our function
    generateBoard(array, size, 0);

    // Remove cells based on difficulty
    removeCells(array, size, difficulty);

    // Printing the initial board that has been generated using our random function
    printBoard(array, size);

    //TAKING USER INPUT 
    while(true) { 
    cout<<"Enter Row no: ";
    cin>>row;
    cout<<"Enter Column no: ";
    cin>>column;
    cout<<"Enter Value: ";
    cin>>value;
    
    //Checking if user wants to quit
    if (row == 0 && column == 0 && value == 0) {
    cout << "Exiting the game. Thanks for playing!\n";
    break; // Exit the while loop
    }
    //If not, then check for correct or incorrect input
    if(row >= 1 && row <= 9 && column >=1 && column <= 9 && value >= 1 && value <= 9) {
        if (IsTheMoveValid(array, row - 1, column - 1, value, size)) {
            array[row - 1][column - 1] = value;
            printBoard(array, size);
         }
        else{
             cout << "Invalid move! That number conflicts with Sudoku rules.\n";
         }
        }
    else{
        cout << "Invalid input! Please enter numbers ranging from 1 to 9.\n";
    continue;   
        }
    }
     return 0;
}
