# David Ibegbu
# CS 481 
# 02-06-2025

import matplotlib.pyplot as plt
import numpy as np
import os

# Define the grid
grid = [
    ['S', '-', '-', 'X', '-', '-', '-', 'G'],
    ['-', 'X', '-', 'X', '-', 'X', '-', '-'],
    ['-', 'X', '-', '-', '-', 'X', 'X', '-'],
    ['-', '-', '-', 'X', 'X', '-', '-', '-'],
    ['X', 'X', '-', '-', '-', '-', 'X', 'X'],
    ['-', '-', 'X', 'X', 'X', '-', '-', '-'],
    ['-', 'X', '-', '-', '-', '-', 'X', '-'],
    ['-', '-', '-', 'X', 'X', '-', '-', '-']
]

# Convert the grid to a numerical representation for visualization
# S = 2 (Start), G = 3 (Goal), X = 1 (Obstacle), - = 0 (Walkable)
numeric_grid = np.zeros((8, 8), dtype=int)

for i in range(8):
    for j in range(8):
        if grid[i][j] == 'S':
            numeric_grid[i][j] = 2
        elif grid[i][j] == 'G':
            numeric_grid[i][j] = 3
        elif grid[i][j] == 'X':
            numeric_grid[i][j] = 1
        else:
            numeric_grid[i][j] = 0

# Create a color map
cmap = plt.cm.get_cmap('viridis', 4)  # 4 distinct colors for S, G, X, and -
colors = [cmap(0), cmap(1), cmap(2), cmap(3)]  # Assign colors to each value

# Plot the grid
plt.figure(figsize=(6, 6))
plt.imshow(numeric_grid, cmap=cmap, vmin=0, vmax=3)

# Add labels for S and G
for i in range(8):
    for j in range(8):
        if grid[i][j] == 'S':
            plt.text(j, i, 'S', ha='center', va='center', fontsize=12, color='white')
        elif grid[i][j] == 'G':
            plt.text(j, i, 'G', ha='center', va='center', fontsize=12, color='white')

# Customize the plot
plt.xticks([])
plt.yticks([])
plt.title("8x8 Map Visualization")

# Define save directory
save_dir = r"C:\Users\davib\OneDrive\Documents\Kettering Courses\CS 481"
save_path = os.path.join(save_dir, "map_visualization.png")

# Save the plot instead of just showing it
plt.savefig(save_path, dpi=300, bbox_inches='tight')
plt.close()  # Close the plot to avoid GUI pop-ups in non-interactive environments

print(f"Map visualization saved successfully at: {save_path}")
