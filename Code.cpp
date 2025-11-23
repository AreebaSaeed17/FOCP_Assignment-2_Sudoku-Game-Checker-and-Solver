#include<iostream>
using namespace std; 
bool IsTheMoveValid(int array[9][9], int rows, int columns, int input){
    //Checking each row by iterating through its columns
    bool IsInThisRow[10]={false};
    for(int column=0; column<9; column++){
        int CurrentCellValue = array[rows][columns];
        //value is only needed inside the loop for the current cell.
        if(CurrentCellValue!=0){
            IsInThisRow[CurrentCellValue];
            return false;
        }
        else{
             IsInThisRow[CurrentCellValue]=true;
        }
    }

    //Checking each column by iterating through its rows

    bool IsInThisColumn[10]={false};
    for(int rows=0; rows<9; rows++){
        int CurrentCellValue=array[rows][columns];
        if(CurrentCellValue!=0){
            IsInThisColumn[CurrentCellValue];
            return false;
        }
        else{
            IsInThisColumn[CurrentCellValue]=true;
        }
    }

    //Checking for each grid (3x3)

    bool IsInThisGrid[10]={false};
    int StartingRowOfBox= (rows/3)*3;
    int StartingColOfBox = (columns/3)*3;

    for(int rows=0; rows<StartingRowOfBox+3; rows++){
        for(int columns=0; columns<StartingColOfBox+3; columns++){
            int CurrentCellValue=array[rows][columns];
            if(CurrentCellValue!=0){
                IsInThisGrid[CurrentCellValue];
                return false;
            }
            else{
                IsInThisGrid[CurrentCellValue]=true;
            }
        }
    }
}
int main(){
    int size=9;
    int array[size][size]={
    {8, 0, 9, 7, 0, 4, 6, 1, 0},
    {5, 0, 7, 3, 2, 6, 4, 8, 9},
    {0, 3, 0, 1, 9, 8, 7, 0, 0},
    {2, 4, 0, 9, 0, 3, 0, 0, 6},
    {0, 9, 1, 0, 7, 0, 2, 3, 8},
    {3, 0, 5, 6, 0, 2, 0, 4, 0},
    {1, 0, 0, 5, 6, 7, 3, 9, 4},
    {0, 6, 0, 8, 3, 9, 0, 2, 5},
    {9, 0, 3, 2, 0, 1, 0, 0, 7}
    };
    cout<<"_________Welcome to the Sudoku Game_________\n";
    cout<<"Here's the grid to be solved:\n";
    for(int i=0; i<size; i++){
        for(int j=0; j<size;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}