# David Ibegbu
# CS 481 
# 02-06-2025

import matplotlib.pyplot as plt
import numpy as np
import os

# Define the directory to save the image
save_dir = r"C:\Users\davib\OneDrive\Documents\Kettering Courses\CS 481"
os.makedirs(save_dir, exist_ok=True)  # Ensure the directory exists

# Define the grid with the path marked by '*'
grid = [
    ['S', '*', '*', 'X', '*', '*', '*', 'G'],
    ['-', 'X', '*', 'X', '*', 'X', '-', '-'],
    ['-', 'X', '*', '*', '*', 'X', 'X', '-'],
    ['-', '-', '-', 'X', 'X', '-', '-', '-'],
    ['X', 'X', '-', '-', '-', '-', 'X', 'X'],
    ['-', '-', 'X', 'X', 'X', '-', '-', '-'],
    ['-', 'X', '-', '-', '-', '-', 'X', '-'],
    ['-', '-', '-', 'X', 'X', '-', '-', '-']
]

# Convert the grid to a numerical representation for visualization
# S = 2 (Start), G = 3 (Goal), X = 1 (Obstacle), - = 0 (Walkable), * = 4 (Path)
numeric_grid = np.zeros((8, 8), dtype=int)

for i in range(8):
    for j in range(8):
        if grid[i][j] == 'S':
            numeric_grid[i][j] = 2  # Start
        elif grid[i][j] == 'G':
            numeric_grid[i][j] = 3  # Goal
        elif grid[i][j] == 'X':
            numeric_grid[i][j] = 1  # Obstacle
        elif grid[i][j] == '*':
            numeric_grid[i][j] = 4  # Path
        else:
            numeric_grid[i][j] = 0  # Walkable

# Create a color map
cmap = plt.cm.get_cmap('viridis', 5)  # 5 distinct colors for S, G, X, -, and *
colors = [cmap(0), cmap(1), cmap(2), cmap(3), cmap(4)]  # Assign colors to each value

# Plot the grid
plt.figure(figsize=(6, 6))
plt.imshow(numeric_grid, cmap=cmap, vmin=0, vmax=4)

# Add labels for S, G, and *
for i in range(8):
    for j in range(8):
        if grid[i][j] == 'S':
            plt.text(j, i, 'S', ha='center', va='center', fontsize=12, color='white')
        elif grid[i][j] == 'G':
            plt.text(j, i, 'G', ha='center', va='center', fontsize=12, color='white')
        elif grid[i][j] == '*':
            plt.text(j, i, '*', ha='center', va='center', fontsize=12, color='black')

# Customize the plot
plt.xticks([])
plt.yticks([])
plt.title("8x8 Map with BFS Path Visualization")

# Save the figure
save_path = os.path.join(save_dir, "BFS_Path_Visualization.png")
plt.savefig(save_path)
plt.show()

# Output the save path
save_path