// CS 481
// David Ibegbu
// 02-06-2025

import java.util.*;

class Node {
    int x, y; // Coordinates of the node
    Node parent; // Parent node to reconstruct the path

    Node(int x, int y, Node parent) {
        this.x = x;
        this.y = y;
        this.parent = parent;
    }
}

public class BFS_8x8_Map {
    // Directions for moving in 4 possible directions (up, down, left, right)
    private static final int[] dx = {-1, 1, 0, 0};
    private static final int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        // Define the 8x8 grid map
        char[][] grid = {
            {'S', '-', '-', 'X', '-', '-', '-', 'G'},
            {'-', 'X', '-', 'X', '-', 'X', '-', '-'},
            {'-', 'X', '-', '-', '-', 'X', 'X', '-'},
            {'-', '-', '-', 'X', 'X', '-', '-', '-'},
            {'X', 'X', '-', '-', '-', '-', 'X', 'X'},
            {'-', '-', 'X', 'X', 'X', '-', '-', '-'},
            {'-', 'X', '-', '-', '-', '-', 'X', '-'},
            {'-', '-', '-', 'X', 'X', '-', '-', '-'}
        };

        // Find the start and goal positions
        Node start = null, goal = null;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (grid[i][j] == 'S') start = new Node(i, j, null);
                if (grid[i][j] == 'G') goal = new Node(i, j, null);
            }
        }

        // Perform BFS
        Node result = bfs(grid, start, goal);

        // Reconstruct and print the path
        if (result != null) {
            System.out.println("Path found!");
            printPath(result, grid);
        } else {
            System.out.println("No path found.");
        }
    }

    private static Node bfs(char[][] grid, Node start, Node goal) {
        Queue<Node> queue = new LinkedList<>();
        boolean[][] visited = new boolean[8][8]; // Track visited nodes

        queue.add(start);
        visited[start.x][start.y] = true;

        while (!queue.isEmpty()) {
            Node current = queue.poll();

            // Check if current node is the goal
            if (current.x == goal.x && current.y == goal.y) {
                return current;
            }

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int nx = current.x + dx[i];
                int ny = current.y + dy[i];

                // Check if the neighbor is within bounds, walkable, and not visited
                if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && grid[nx][ny] != 'X' && !visited[nx][ny]) {
                    queue.add(new Node(nx, ny, current));
                    visited[nx][ny] = true;
                }
            }
        }

        return null; // No path found
    }

    private static void printPath(Node node, char[][] grid) {
        List<Node> path = new ArrayList<>();
        while (node != null) {
            path.add(node);
            node = node.parent;
        }

        // Reverse the path to start from 'S' to 'G'
        Collections.reverse(path);

        // Mark the path on the grid
        for (Node n : path) {
            if (grid[n.x][n.y] != 'S' && grid[n.x][n.y] != 'G') {
                grid[n.x][n.y] = '*';
            }
        }

        // Print the grid with the path
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                System.out.print(grid[i][j] + " ");
            }
            System.out.println();
        }
    }
}
