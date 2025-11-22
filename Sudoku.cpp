#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std; 
void printboard(int board[9][9], int size);

const int size = 9;
int main()
{
srand(time(0));
int r;
//hardcoding solved board
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
//replacing random values with zeroes
    for(int i=0; i<size; i++)
    {   for(int j=0; j<size;j++)
        {   
            
            r = rand() % 10;
            if(r < 4) 
            array[i][j] = 0;
        } 
    }
//printing board,
cout << "--- Initial Sudoku Board ---" << endl;
     printboard(array, size); 

//taking input 
while(true)
{
    
int row,column,value;
cout<<"Enter row no: ";
cin>>row;
cout<<"Enter column no: ";
cin>>column;
cout<<"Enter Value: ";
cin>>value;
if (row < 1 && row > 9 && column < 1 && column > 9 && value < 1 && value > 9) 
   
{array[row-1][column-1]=value;
// again printing
printboard(array, size);}
else
cout << "Invalid input! Please enter numbers from 1 to 9.\n";
continue;
}
    return 0;
}
//function definitions

void printboard(int board[9][9], int size)
{
for(int i=0; i<size; i++)
    {if (i % 3 == 0) 
        cout << "+-------+-------+-------+" << endl;
        for(int j=0; j<size;j++)
        { if (j % 3 == 0) 
           cout << "| ";
           cout<< board[i][j]<<" ";
        }  cout << "|" << endl;
    }   cout << "+-------+-------+-------+" << endl;



}

