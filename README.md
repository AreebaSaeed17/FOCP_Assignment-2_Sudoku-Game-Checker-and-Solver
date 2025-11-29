# FOCP_Assignment-2_Sudoku-Game-Checker-and-Solver
# TITLE AND TEAM INFORMATION 
# TITLE : SUDOKU GAME CHECKER AND SOLVER
# TEAM NAME : GAME DEV ENGINEERS 🕹️✨
# TEAM MEMBERS AND ROLES:
1. Areeba Saeed : Team Leader & Programmer 1       
2. Urooj Fatima : Programmer 2 & Logic Designer 
3. Heeba Aamir : Git Manager & Tester
# Overview / Program Description:
We have created a C++-based Sudoku Game, Checker, and Solver that lets players interactively complete a Sudoku puzzle. It uses 2D arrays, modular functions, and strict validation to enforce real Sudoku rules. Players can enter numbers, choose the size of the grid, check validity, request hints, or auto-solve the puzzle. A scoring system rewards correct moves and deducts points for mistakes or help, and the game ends by displaying the final score once the board is fully solved.   
# Why It's Useful:
This project is useful because it involves the application of core programming concepts—such as arrays, recursion, input validation, and modular design—to a real-world puzzle. It helps in logic building and implementation of logic. Features like the checker, hint system, and scoring mechanism also mimic real puzzle applications, making the game both educational and practical. The scoring system encourages efficient play, while the modular structure reinforces clean problem-solving and debugging skills. Overall, the project offers both an enjoyable puzzle game and a solid learning opportunity for understanding how structured logic can be transformed into a functional program.   

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
