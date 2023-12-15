#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 10 

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V], int n) {
    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V], int n) {
    int parent[V]; // Array to store the constructed MST
    int key[V];    // Key values used to pick the minimum weight edge

    bool mstSet[V]; // To represent set of vertices included in MST

    
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    
    key[0] = 0; 

    
    for (int count = 0; count < n - 1; count++) {
        
        int u = minKey(key, mstSet, n);

        
        mstSet[u] = true;

        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    
    printMST(parent, graph, n);
}

int main() {
    int n;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    
    primMST(graph, n);

    return 0;
}


// Testcase

// Enter the number of vertices in the graph: 5
// Enter the adjacency matrix for the graph:
// 0 2 0 6 0
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9
// 0 5 7 9 0
// Edge   Weight
// 0 - 1    2
// 1 - 2    3
// 0 - 3    6
// 1 - 4    5