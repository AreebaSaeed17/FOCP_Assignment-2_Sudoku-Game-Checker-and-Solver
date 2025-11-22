#include<iostream>
using namespace std; 
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