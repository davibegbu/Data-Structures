//David Ibegbu

#ifndef ASTAR_TILE_STACK_H
#define ASTAR_TILE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "AStarTileMap.h"

// Structure for a stack node
typedef struct AStarTileStackNode {
    AStarTile *tile;
    struct AStarTileStackNode *next;
} AStarTileStackNode;

// Function declarations
void stackInit(AStarTileStackNode **top) {
    *top = NULL;  // Initialize stack to NULL
}

void stackPush(AStarTileStackNode **top, AStarTile *tile) {
    AStarTileStackNode *newNode = (AStarTileStackNode *)malloc(sizeof(AStarTileStackNode));
    newNode->tile = tile;
    newNode->next = *top;
    *top = newNode;
}

AStarTile *stackPop(AStarTileStackNode **top) {
    if (*top == NULL) {
        return NULL;  // Stack is empty
    }
    AStarTileStackNode *node = *top;
    *top = (*top)->next;
    AStarTile *tile = node->tile;
    free(node);
    return tile;
}

void stackPrint(AStarTileStackNode *top) {
    printf("Tile stack (top to bottom): ");
    AStarTileStackNode *current = top;
    while (current != NULL) {
        printf("(%d,%d) ", current->tile->x, current->tile->y);
        current = current->next;
    }
    printf("\n");
}

void stackDelete(AStarTileStackNode **top) {
    while (*top != NULL) {
        stackPop(top);  // Pop and free all nodes
    }
}

#endif
