README - N-Queens Solver

📌 Overview
This repository contains an **N-Queens Solver**, implemented in **Java**, using an **iterative repair algorithm** to find solutions efficiently. The program randomly places queens on a board and iteratively swaps them to minimize attacks until a valid solution is found.

📁 Project Structure

**Main Algorithm**
- **SolverNQueen.java** → Implements the iterative repair algorithm for solving the N-Queens problem.

🛠️ How It Works
1. **Board Initialization:** A random **N x N chessboard** is generated with **one queen per row**.
2. **Conflict Calculation:** The algorithm **counts diagonal attacks** using an efficient diagonal tracking method.
3. **Iterative Repair:**
   - Queens are swapped to **reduce conflicts**.
   - If no swaps lead to improvement, a new random board is generated.
4. **Solution Detection:**
   - The process continues **until no conflicts remain**.
   - Once a solution is found, the board is printed.
   - The number of board resets and the time taken are displayed.

📌 Key Functions
- **iterativeRepair(n)** → Main function to solve the N-Queens problem using iterative repair.
- **generateBoard(n)** → Generates a **random N-Queens board**.
- **findAttacks(board)** → Counts the number of **queens attacking each other**.
- **swapQueens(board, i, j)** → Swaps two queens and returns the modified board.
- **isAttacked(board, i, j)** → Checks if two queens are attacking each other.
- **printBoard(board, n)** → Prints the board configuration.

🔗 Dependencies
- **Java Standard Libraries:** `java.util.Random`, `java.time.Duration`, `java.time.Instant`, `java.time.LocalTime`, `java.time.format.DateTimeFormatter`

🚀 How to Compile & Run

**Compiling the Code**

javac SolverNQueen.java


### 🔹 **Running the Program**

java SolverNQueen


## 📊 Example Output

Here is the board that is generated:
3 1 4 0 2

Solution found. This Board has no attacks:
3 1 4 2 0

There were 5 board resets.

Time taken (Minutes:Seconds:Milliseconds.Microseconds): 00:00:002.123456

