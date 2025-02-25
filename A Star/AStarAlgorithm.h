//David Ibegbu

#ifndef ASTARALGORITHM_H
#define ASTARALGORITHM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AStarTileMap.h"  // Separate but used for tile structure
#include "AStarTileHeap.h"
#include "AStarTileStack.h"

// Direction vectors for moving North, South, East, West
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1};

// Function prototypes
void aStarProcessNeighborTile(AStarTile map[10][10], AStarTile* current, AStarTile* neighbor, AStarTile* destination, AStarTileHeap* openSet);
bool aStarRunSearch(AStarTile map[10][10], AStarTile* source, AStarTile* destination);
void aStarTracePath(AStarTile* destination);

// Main A* search function
bool aStarRunSearch(AStarTile map[10][10], AStarTile* source, AStarTile* destination) {
    AStarTileHeap openSet;
    heapInit(&openSet);

    // Initialize the starting tile
    source->G = 0;
    source->H = abs(source->x - destination->x) + abs(source->y - destination->y);  // Manhattan heuristic
    source->F = source->G + source->H;
    heapInsert(&openSet, source);
    source->inOpenSet = 1;

    while (!heapIsEmpty(&openSet)) {
        AStarTile* current = heapExtractMin(&openSet);
        current->inClosedSet = 1;

        // If we reached the destination, return true
        if (current == destination) {
            return true;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];
            if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
                aStarProcessNeighborTile(map, current, &map[newX][newY], destination, &openSet);
            }
        }
    }
    return false;  // No path found
}

// Function to process a neighbor tile during A* search
void aStarProcessNeighborTile(AStarTile map[10][10], AStarTile* current, AStarTile* neighbor, AStarTile* destination, AStarTileHeap* openSet) {
    if (neighbor->isObstacle || neighbor->inClosedSet) return;

    // Assume a step cost of 1 for each move
    int stepCost = 1;

    // Calculate the tentative G score
    int tentativeG = current->G + stepCost;

    // If the neighbor is not in the open set or a shorter path is found
    if (!neighbor->inOpenSet || tentativeG < neighbor->G) {
        neighbor->parent = current;  // Set the parent to current for path tracing
        neighbor->G = tentativeG;    // Update G-value
        neighbor->H = abs(neighbor->x - destination->x) + abs(neighbor->y - destination->y);  // Manhattan heuristic
        neighbor->F = neighbor->G + neighbor->H;  // Update F-value

        // Insert into the open set if not already there
        if (!neighbor->inOpenSet) {
            heapInsert(openSet, neighbor);
            neighbor->inOpenSet = 1;
        }
    }
}



// Function to trace back the path from the destination tile to the source tile
void aStarTracePath(AStarTile* destination) {
    AStarTile* current = destination;
    while (current != NULL) {
        current->inPath = 1;  // Mark the tile as part of the path
        current = current->parent;  // Move to the parent tile
    }
}


#endif  // ASTARALGORITHM_H
