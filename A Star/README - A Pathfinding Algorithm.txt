README - A* Pathfinding Algorithm Implementation

📌 Overview
This repository contains an **A* pathfinding algorithm** implementation written in **C**. The A* algorithm efficiently finds the shortest path between a **source tile** and a **destination tile** in a **10x10 grid-based map**. This project includes various supporting data structures such as **min-heaps, stacks, and tile maps** for efficient computation.

📁 Project Structure
 **Main Algorithm**
- **AStarAlgorithm.h** → Implements the A* search algorithm, including heuristics, path tracing, and tile evaluation.
- **AStarTileMap.h** → Defines the **grid structure** and initializes the tile map with obstacles.

**Data Structures**
- **AStarTileHeap.h** → Implements a **min-heap** to efficiently manage open set tiles based on their F-cost.
- **AStarTileStack.h** → Implements a **stack** to store the final path after a successful search.

**Execution File**
- **Project1.c** → Main execution file that initializes the map, runs the A* algorithm, and prints results.

🛠️ How It Works
1. **Grid Initialization:** A **10x10 map** is initialized with random obstacles.
2. **A* Search Execution:** The algorithm starts from the **source tile (0,0)** and finds the shortest path to **destination tile (9,9)**.
3. **Path Reconstruction:** If a valid path is found, the algorithm **traces back the shortest route** and marks it.
4. **Heuristic Calculation:** Uses **Manhattan Distance** as the heuristic for estimating the shortest path.
5. **Data Structures:**
   - **Min-heap** maintains open nodes sorted by **F-cost**.
   - **Stack** stores the final path for backtracking.

📌 Key Functions
- **aStarRunSearch()** → Main function running the A* algorithm.
- **aStarProcessNeighborTile()** → Updates neighbors based on heuristic cost.
- **heapInsert(), heapExtractMin()** → Operations for the **open set**.
- **mapInit()** → Initializes the grid and places obstacles.
- **aStarTracePath()** → Traces and prints the shortest path.

🔗 Dependencies
- **Standard C libraries:** `stdio.h`, `stdlib.h`, `stdbool.h`
- **Custom headers:** `AStarAlgorithm.h`, `AStarTileMap.h`, `AStarTileHeap.h`, `AStarTileStack.h`

🚀 How to Compile & Run
**Compiling the Code**

gcc Project1.c -o a_star_algorithm


**Running the Program**

./a_star_algorithm


📊 Example Output

Map before A* search:
_ _ _ X _ _ _ _ _ _
_ _ X _ _ _ X _ _ _
_ _ _ _ X _ _ _ _ _
_ X _ _ _ _ X _ _ _
_ _ _ X _ _ _ _ _ _
_ _ _ _ _ _ _ X _ _
_ _ X _ _ _ _ _ X _
_ _ _ _ _ X _ _ _ _
_ _ _ _ _ _ X _ _ _
_ _ _ _ _ _ _ _ _ _

Map after A* search:
* * * X _ _ _ _ _ _
_ _ X * * _ X _ _ _
_ _ _ _ X * * * _ _
_ X _ _ _ _ X * _ _
_ _ _ X _ _ * * * *
_ _ _ _ _ _ * X _ *
_ _ X _ _ _ * * X *
_ _ _ _ _ X * * * *
_ _ _ _ _ _ X * * *
_ _ _ _ _ _ _ _ * *




