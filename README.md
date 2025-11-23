# FOCP_Assignment-2_Sudoku-Game-Checker-and-Solver
Explaining my function "IsTheMoveValid" to check validity of the user choice in the sudoku board. It has 3 check points which completely verify if the number the user wants to input is a valid move for the location on the board that he chose.  
This works on the logic of nested loops, 2D arrays and Boolean.  
At the start of each segment of the checks, I have created an array of 10 elements (0-9) stored as false.  
It first enters each row using an outer loop, inside each row it checks all of its columns    
It retrieves the value that is currently at the sudoku board then runs some checks on it.  

I'll explain using the Row checker as an example:  
  -IsInThisRow[CurrentCellValue] looks up the boolean value at the index equal to the number in the cell.  
  lets say If CurrentCellValue = 5, we check IsInThisRow[5].  
  -If it’s true, that means the number 5 was already seen in this row → duplicate detected.The  condition is true, so the function immediately returns false. This means the row is invalid because Sudoku rules forbid repeating numbers.  

  -If the if condition is false (number not seen before), we execute:  
  IsInThisRow[CurrentCellValue] = true;  
  This sets the boolean at that index to true, so next time we know this number exists in the row.  

  -First time seeing a number → mark it as seen.  
  -Second time seeing the same number → return false immediately.  
  If the first part is true and it goes on to return false, the next line of code doesn't run.  
