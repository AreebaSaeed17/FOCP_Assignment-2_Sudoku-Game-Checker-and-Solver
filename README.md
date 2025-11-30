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
# Program Design & Logic:
# Modular Structure-Functions:
## Function Descriptions
We have included the following functions to have a modular structure:
| **Function**       | **Description** |
|--------------------|-----------------|
| **GenerateBoard**  | Generates a complete Sudoku board of the chosen size using random numbers. |
| **removeCells**    | Removes selected numbers from the generated board to create a playable puzzle. |
| **printBoard**     | Displays the Sudoku board — initial board, updates after each move or hint, and the final solved board. |
| **IsTheMoveValid** | Validates whether the user's input follows Sudoku rules (no repetition in row, column, or subgrid). Also supports other functions like the solver and checker. |
| **solver**         | On-demand function that attempts to solve the current board. Shows the solved board if a solution exists; otherwise shows an error message. |
| **hint**           | Provides a correct hint by mapping a random empty cell to the solver’s solution, ensuring consistency between hints and the final solution. |
| **checker**        | Checks the entire current board to ensure it follows Sudoku rules by validating each cell individually. |
| **Game_Menu**      | Displays the list of commands/instructions for playing the game. |
| **delay**          | Pauses program execution for a specified number of seconds. |
| **setColor**       | Adds color-coded output to enhance display and user interface. |
# Grid Handling:
The Sudoku board is stored using two-dimensional array (of the size specified by the user), where each element represents one cell.    
1. Empty space in the grid indicates an empty cell.      
2. The grid is updated whenever the user enters a number, uses a hint, or when the solver fills a value.      
3. All validation checks—row, column, and subgrid—are applied directly to this array.     
4. The board is printed after every update to maintain real-time feedback during gameplay.        
This ensures that the game state is always consistent and accurately reflects the rules of Sudoku.         
# Function Descriptions:
### generateBoard () : 
Creates a completely valid Sudoku board using random numbers and recursive call logic. It iterates through rows, column by column and tries a random number for that cell. In this way, it tries to fill a row. If at any cell in that specific row, no random number is valid for a particular of times we try for that cell, we reset the whole row to zero again and then try again starting from column 1. This process is repeated untill the whole row is filled and is valid according to the sudoku rules ( we have used our IsTheMoveValid function for this purpose). It ensures the final board adheres to Sudoku rules before any cells are removed.   
### removeCells (): 
Removes numbers from cells randomly based on the difficulty level specified by the user to create a playable board. In easy level, 30% of the grid is emptied, in medium difficulty level, 50% of the grid is emptied while in hard level, 70% of the grid is emptied. The cells are emptied randomly but in a way that ensures that the board has a solution.   
### printBoard(): 
Prints the Sudoku board in a clean grid format. It supports dynamic sub-grid sizes (1×1, 2×2, 3×3), automatically draws vertical and horizontal separators and shows the board after every major action (move, hint, solver, or initial display).  
### IsTheMoveValid(): 
Explaining my function "IsTheMoveValid" to check validity of the user choice in the sudoku board. It has 3 check points which completely verify if the number the user wants to input is a valid move for the location on the board that he chose. This works on the logic of nested loops, 2D arrays and Boolean.  
At the start of each segment of the checks, I have created an array of 10 elements (0-9) stored as false. It first enters each row using an outer loop, inside each row, it checks all of its columns. It retrieves the value that is currently at the sudoku board then runs some checks on it.  
I'll explain using the Row checker as an example:  
i. IsInThisRow[CurrentCellValue] looks up the boolean value at the index equal to the number in the cell.  
  lets say If CurrentCellValue = 5, we check IsInThisRow[5].  
ii. If it’s true, that means the number 5 was already seen in this row → duplicate detected.The  condition is true, so the function immediately returns false. This means the row is invalid because Sudoku rules forbid repeating numbers.  
iii. If the if condition is false (number not seen before), we execute:  
  IsInThisRow[CurrentCellValue] = true;  
This sets the boolean at that index to true, so next time we know this number exists in the row.  
iv. First time seeing a number → mark it as seen.  
v. Second time seeing the same number → return false immediately.  
If the first part is true and it goes on to return false, the next line of code doesn't run.
### solver(): 
The solver function is designed in a way that it takes the current board from the user when it is called tries to solve it. It iterates through each row one by one, checking each column and tries to find an empty cell. Once an empty cell is found, it tries each number for that cell, ranging from 1 to the size of the grid. It uses the IsTheMoveValid function to determine whether a number can be placed at that cell. When the first possible number is found, the function is again recursively called to try to solve the rest of the board with this new number in place. If the rest of the board isn't solved in the recursive call, then we set that cell to zero again and tries the next number. This process repeats recursiely until all the cells are filled and the board is solved. Since the solver takes the current board from the user, there might be a condition where there is no possible solution of the board due to certain inputs of the user (since the inputs are validated through IsTheMoveValid function, there are high possibilities that the input would be valid according to the rules of sudoku but it will eventually lead to condition where no solution is possible i.e. each sudoku board has one unique solution). When the solver is unable to solve the board, then a message is displayed that no solution is available.
### hint(): 
The hint function is programmed in a way that it provides the user a valid hint that is consistent with the solution generated by the solver.It provides hint at random places rather than user specified cells to mimic real sudoku game. The hint functions first generates a random row and column and checks that whether the cell at that place is empty. If not, then the function is recursively called again. If the cell is empty, then a temporary copy of the current board is generated which is then sent to the solver function which then provides a valid number at that place according to the solution. This is done as to keep our hints consistent with the solution. If the hints were to be validated by the IsTheMoveValid function, then there's a high possibility that such hints will lead to a board that doesn't have a solution.
After the solver function provides the number at that place, we assign it to that cell at our current array and display a message that tells the user that a particular number was placed at this particular location.
### checker(): 
On demand, it checks if the current grid state satisfies Sudoku rules. The checker function checks the entire Sudoku board at any point during the game to ensure correctness. It iterates through every non-zero cell, temporarily removing each cell’s value and then testing whether placing that same value back is valid according to Sudoku rules. If any conflict is detected—such as a repeated number in the same row, column, or 3×3 subgrid—the board is considered invalid. This approach provides players with a real-time check, allowing them to see whether their current moves maintain a correct and solvable board.
### Game_Menu(): 
The Game_Menu function displays a menu of available player actions, including making a move, getting a hint, requesting the complete solution, checking the board, or quitting the game. To enhance readability, the menu incorporates color formatting, making it easier for players to navigate and select their desired action.
### delay(): 
It pauses program execution for a given number of seconds using sleep_for(), used for creating loading screens and giving players time to read messages.
### setColor():
Uses Windows API (SetConsoleTextAttribute) to apply color to terminal text, improving readability and user experience.
# Logic Flow:
1. display of welcome message and rules. User selects grid size and difficulty.
2. generateBoard() creates a complete valid board.
3. removeCells() removes values based on difficulty.
4. printBoard() displays the playable puzzle.
5. Initialize Game State : Score = 100, Mistakes = 0 (max 5), gameOver = false.
6. Gameplay Loop : Display menu and take user choice:
Make Move: Validate using IsTheMoveValid(); update board or deduct points.
Hint: hint() reveals a correct value and reduces score.
Full Solution: solver() solves the board and ends the game.
Check Board: checker() verifies correctness.
Quit: Exit game.
7. After each action, updated score and mistakes are displayed. If score ≤ 0 or mistakes > 5 → game ends.
8. Game ends when user complete the games, quits or loses. Then the final message is displayed.
# Execution Instructions :
## ON A COMPILER:
Compile the program on c++ compatible compiler and then run it.  
Sample Output:   
![Input_Screenshot](https://github.com/AreebaSaeed17/FOCP_Assignment-2_Sudoku-Game-Checker-and-Solver/blob/ef29b71e668a6dc0044e3883bcf9fdc791e6251e/outputs/1.png)
## ON GitBash:

# AI Tool Reflection:
AI tools were used selectively to assist with specific technical parts of the project, while the main logic, implementation, and program design were developed by the group. The following summarizes where AI assistance was applied:   
1. AI assistance was used to implement the setColor() function correctly using the Windows console API (GetStdHandle and SetConsoleTextAttribute). AI helped provide the proper syntax and structure, while the choice of colors and integration into the game (menus, warnings, success messages, etc.) was implemented by the group.
2. AI guidance was used to write a clean and portable version of the delay() function using std::this_thread::sleep_for() and std::chrono::seconds. This allowed the game to include smooth pauses for loading screens and improved user experience. The placement of delays within the game flow was done by the group.
3. Initially to make the solver function , the approach of our team was to reset only the cells changed in the solver when a dead end was reached and then try again with different numbers starting again from the first empty cell. When this method failed to produce a consistent solution, AI assistance helped identify the problem that suggested a more reliable strategy to validate the solvability of the board immediately after placing a number in the first empty cell and allow recursive backtracking to handle resets automatically. This advice improved the correctness and stability of the solver, while the full implementation and integration into the game were completed by the group.
# Future Enhancements: 
## Graphical User Interface (GUI) :
Implementing a GUI using frameworks like Qt, SFML, or SDL would create a more interactive and visually appealing experience compared to the console-based interface.
## Database Integration:
Integrate a database (e.g., SQLite or MySQL) to store player profiles, previous scores, leaderboards, puzzle completion history, etc. This would make the game more persistent and player-focused.
## Timer Based Scoring :
Introduce a countdown or stopwatch system to incorporate time-based scoring and reward faster puzzle completion.
## Save & Reload:
Allow players to save the current board state to a file and reload it later to continue their progress.


