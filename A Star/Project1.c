//David Ibegbu

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "AStarAlgorithm.h"
#include "AStarTileMap.h"

// Function prototypes for distance functions
double euclideanDistance(int aX, int aY, int bX, int bY);
double manhattanDistance(int aX, int aY, int bX, int bY);

// Randomly place obstacles
void placeRandomObstacles(AStarTile map[10][10], int numObstacles);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the map
    AStarTile map[10][10];
    mapInit(map, &manhattanDistance);

    // Place random obstacles on the map
    placeRandomObstacles(map, 10);  // Example: Place 10 random obstacles

    // Define source and destination tiles
    AStarTile* source = &map[0][0];
    AStarTile* destination = &map[9][9];

    // Print the map before A* search
    mapPrint(map, BEFORE_SEARCH);

    // Run the A* search algorithm
    if (aStarRunSearch(map, source, destination)) {
        // Print the map after A* search
        mapPrint(map, AFTER_SEARCH);

        // Trace and print the final path stack
        aStarTracePath(destination);  // Call with only the destination tile

    } else {
        printf("No path found.\n");
    }

    return 0;
}

// Randomly place obstacles on the map
void placeRandomObstacles(AStarTile map[10][10], int numObstacles) {
    int placed = 0;
    while (placed < numObstacles) {
        int x = rand() % 10;
        int y = rand() % 10;

        // Ensure the obstacle is not placed at the source, destination, or on an existing obstacle
        if ((x == 0 && y == 0) || (x == 9 && y == 9) || map[x][y].isObstacle) {
            continue;
        }

        map[x][y].isObstacle = 1;
        placed++;
    }
}

// Distance functions for Euclidean and Manhattan distance calculations
double euclideanDistance(int aX, int aY, int bX, int bY) {
    return sqrt((aX - bX) * (aX - bX) + (aY - bY) * (aY - bY));
}

double manhattanDistance(int aX, int aY, int bX, int bY) {
    return abs(aX - bX) + abs(aY - bY);
}
