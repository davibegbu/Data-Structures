//David Ibegbu

#ifndef ASTAR_TILE_MAP_H
#define ASTAR_TILE_MAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AStarTileMap.h"

// Define constants for BEFORE_SEARCH and AFTER_SEARCH modes
#define BEFORE_SEARCH 0
#define AFTER_SEARCH 1

// Define the structure for a tile in the A* algorithm
typedef struct AStarTile {
    int x, y;  // Coordinates of the tile
    int G, C, H, F;  // G, C, H, and F cost values
    struct AStarTile *parent;  // Parent tile pointer
    int isObstacle;  // 1 if the tile is an obstacle, 0 otherwise
    int inOpenSet;  // 1 if the tile is in the open set
    int inClosedSet;  // 1 if the tile is in the closed set
    int inPath;  // 1 if the tile is part of the final path
} AStarTile;

// Declare the mapInit function
void mapInit(AStarTile map[10][10], double (*distanceFunc)(int, int, int, int));

// Initialize the map with random obstacles
void mapInit(AStarTile map[10][10], double (*distanceFunc)(int, int, int, int)) {
    // Initialize the map with default values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j].x = i;
            map[i][j].y = j;
            map[i][j].C = 1;  // Example: cost of 1 for all tiles
            map[i][j].G = 0;
            map[i][j].H = 0;
            map[i][j].F = 0;
            map[i][j].isObstacle = 0;  // By default, no obstacles
            map[i][j].parent = NULL;  // No parent initially
            map[i][j].inOpenSet = 0;
            map[i][j].inClosedSet = 0;
            map[i][j].inPath = 0;
        }
    }

    // Randomly place obstacles on the map
    srand(time(NULL));  // Seed the random number generator with the current time

    int numObstacles = 10;  // Number of obstacles to place (you can adjust this)
    for (int n = 0; n < numObstacles; n++) {
        int randX = rand() % 10;
        int randY = rand() % 10;

        // Ensure the obstacle is not placed at the start or destination
        if ((randX == 0 && randY == 0) || (randX == 9 && randY == 9) || map[randX][randY].isObstacle) {
            n--;  // Retry placing the obstacle
            continue;
        }

        map[randX][randY].isObstacle = 1;  // Place an obstacle
    }
}

// Initialize the map
void mapPrint(AStarTile map[10][10], int mode) {
    if (mode == BEFORE_SEARCH) {
        printf("Map before A* search:\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j].isObstacle) {
                    printf(" X ");
                } else {
                    printf(" _ ");
                }
            }
            printf("\n");
        }
    } else if (mode == AFTER_SEARCH) {
        printf("Map after A* search (F values and path):\n");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j].isObstacle) {
                    printf(" X ");
                } else if (map[i][j].inPath) {
                    printf(" * ");  // Mark path tiles with '*'
                } else if (map[i][j].inClosedSet) {
                    printf("%5.2f ", (float)map[i][j].F);  // Show F value for evaluated tiles, with spacing
                } else {
                    printf(" ? ");
                }
            }
            printf("\n");
        }
    }
}

#endif

