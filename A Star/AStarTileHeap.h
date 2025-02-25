// David Ibegbu

#ifndef ASTAR_TILE_HEAP_H
#define ASTAR_TILE_HEAP_H

#include "AStarTileMap.h"

// Structure for the min-heap
typedef struct AStarTileHeap {
    AStarTile *tiles[100];  // Example heap size (adjust as needed)
    int size;  // Current size of the heap
} AStarTileHeap;

// Initialize the heap
void heapInit(AStarTileHeap *heap) {
    heap->size = 0;  // Initialize heap size to 0
}

// Helper function to swap two tiles in the heap
void swapTiles(AStarTile **a, AStarTile **b) {
    AStarTile *temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up function to maintain min-heap property after insertion
void heapSwapUpTile(AStarTileHeap *heap, int index) {
    while (index > 0 && heap->tiles[(index - 1) / 2]->F > heap->tiles[index]->F) {
        swapTiles(&heap->tiles[(index - 1) / 2], &heap->tiles[index]);
        index = (index - 1) / 2;
    }
}

// Insert a tile into the heap while maintaining the min-heap property
void heapInsert(AStarTileHeap *heap, AStarTile *tile) {
    heap->tiles[heap->size] = tile;
    heapSwapUpTile(heap, heap->size);
    heap->size++;
}

// Heapify down function to maintain min-heap property after extraction
void heapSwapDownTile(AStarTileHeap *heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->tiles[left]->F < heap->tiles[smallest]->F) {
        smallest = left;
    }
    if (right < heap->size && heap->tiles[right]->F < heap->tiles[smallest]->F) {
        smallest = right;
    }

    if (smallest != index) {
        swapTiles(&heap->tiles[index], &heap->tiles[smallest]);
        heapSwapDownTile(heap, smallest);
    }
}

// Extract the tile with the minimum F value from the heap
AStarTile *heapExtractMin(AStarTileHeap *heap) {
    if (heap->size == 0) return NULL;  // Heap is empty

    AStarTile *minTile = heap->tiles[0];
    heap->size--;
    heap->tiles[0] = heap->tiles[heap->size];
    heapSwapDownTile(heap, 0);

    return minTile;
}

// Check if the heap is empty
int heapIsEmpty(AStarTileHeap *heap) {
    return heap->size == 0;
}

// Print the contents of the heap (F values and coordinates)
void heapPrint(AStarTileHeap *heap) {
    printf("Heap contents (F values and coordinates):\n");
    for (int i = 0; i < heap->size; i++) {
        printf("Tile (%d, %d) -> F: %d\n", heap->tiles[i]->x, heap->tiles[i]->y, heap->tiles[i]->F);
    }
    printf("\n");
}

#endif 