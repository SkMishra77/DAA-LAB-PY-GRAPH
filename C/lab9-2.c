#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 10 

int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int n, int src) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];     
    bool sptSet[V]; 

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }


    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
       
        int u = minDistance(dist, sptSet, n);


        sptSet[u] = true;

    
        for (int v = 0; v < n; v++) {
           
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n, src);
}

int main() {
    int n;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}

// I/O


// Enter the number of vertices in the graph: 5
// Enter the adjacency matrix for the graph:
// 0 3 0 7 0
// 3 0 2 0 0
// 0 2 0 1 8
// 7 0 1 0 4
// 0 0 8 4 0
// Enter the source vertex: 0
// Vertex   Distance from Source
// 0                0
// 1                3
// 2                5
// 3                6
// 4                10
