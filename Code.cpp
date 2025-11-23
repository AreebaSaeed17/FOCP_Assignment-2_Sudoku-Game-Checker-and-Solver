#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std; 

//FUNCTION 1
void printboard(int board[9][9], int size)
{
cout<<"Here's the grid to be solved:\n";
for(int i=0; i<size; i++){
    if (i % 3 == 0) {
        cout << "+-------+-------+-------+" << endl;
    }
    for(int j=0; j<size;j++)
        { if (j % 3 == 0) 
           cout << "| ";
           cout<< board[i][j]<<" ";
        }  cout << "|" << endl;
    }   cout << "+-------+-------+-------+" << endl;
}

//FUNCTION-2
bool IsTheMoveValid(int array[9][9], int rows, int columns, int input){

    //Checking each row by iterating through its columns

    //Each index represents a possible Sudoku number:
    bool IsInThisRow[10]={false};
    for(int j=0; j<9; j++){
        //bringing in the value which is in the cell of the board right now
        int CurrentCellValue = array[rows][j];
        //value is only needed inside the loop for the current cell
        //hence I'm declaring it inside the loop

        if(CurrentCellValue!=0){
            if(IsInThisRow[CurrentCellValue]){
            return false;
        }
         //update this number's status in the boolean array as true
        IsInThisRow[CurrentCellValue]=true;
    
    }
       
    }

    //Checking each column by iterating through its rows

    bool IsInThisColumn[10]={false};
    for(int i=0; i<9; i++){
        int CurrentCellValue=array[i][columns];
        if(CurrentCellValue!=0){ 
            //if the value at the index equal to the value in this array is true,
            //it's a duplicate
            //exit from this loop
            if(IsInThisColumn[CurrentCellValue]){
                return false;
            }
            IsInThisColumn[CurrentCellValue]=true;
        }    
        
    }

    //Checking for each grid (3x3)

    bool IsInThisGrid[10]={false};
    int StartingRowOfBox= (rows/3)*3;
    int StartingColOfBox = (columns/3)*3;

    for(int i=StartingRowOfBox; i<StartingRowOfBox+3; i++){
        for(int j=StartingColOfBox ; j<StartingColOfBox+3; j++){
            int CurrentCellValue=array[i][j];
            if(CurrentCellValue!=0){
                if(IsInThisGrid[CurrentCellValue]){
                    return false;
                }
                IsInThisGrid[CurrentCellValue]=true;
               
            }
            
        }
    }

   //Check if the input number is already marked in any of them
    //If yes → return false (invalid)
    //If no → return true (valid)
    return !(IsInThisRow[input] || IsInThisColumn[input] || IsInThisGrid[input]);
}

int main(){
    cout<<"_________Welcome to the Sudoku Game_________\n";
   const int size=9;int row, column, value;
    int array[size][size] = {
    {8, 2, 9, 7, 5, 4, 6, 1, 3},
    {5, 1, 7, 3, 2, 6, 4, 8, 9},
    {4, 3, 6, 1, 9, 8, 7, 5, 2},
    {2, 4, 8, 9, 1, 3, 5, 7, 6},
    {6, 9, 1, 4, 7, 5, 2, 3, 8},
    {3, 7, 5, 6, 8, 2, 9, 4, 1},
    {1, 8, 2, 5, 6, 7, 3, 9, 4},
    {7, 6, 4, 8, 3, 9, 1, 2, 5},
    {9, 5, 3, 2, 4, 1, 8, 6, 7}
};
//This replaces random digits by 0

   srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            //this variable has to be updated every single time. it must be inside the loop
            int randomNum = rand() % 10;
            if (randomNum < 4) array[i][j] = 0;
        }
    }

    //TAKING USER INPUT 
    while(true) { 
    cout<<"Enter Row no: ";
    cin>>row;
    cout<<"Enter Column no: ";
    cin>>column;
    cout<<"Enter Value: ";
    cin>>value;
    if(row >= 1 && row <= 9 && column >=1 && column <= 9 && value >= 1 && value <= 9) {
        if (IsTheMoveValid(array, row - 1, column - 1, value)) {
            array[row - 1][column - 1] = value;
            printboard(array, size);
         }
        else{
             cout << "Invalid move! That number conflicts with Sudoku rules.\n";
         }
        }
    else{
        cout << "Invalid input! Please enter numbers ranging from 1 to 9.\n";
    continue;   
}
    return 0;
}
}