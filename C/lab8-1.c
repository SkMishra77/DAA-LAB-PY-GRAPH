#include <stdio.h>
#include <stdlib.h>

#define V 10 
#define E 20


struct Edge {
    int src, dest, weight;
};


struct Subset {
    int parent, rank;
};


int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}


int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


void kruskalMST(struct Edge edges[], int n, int e) {
    struct Edge result[n]; 
    int i = 0, j = 0;

    
    qsort(edges, e, sizeof(edges[0]), compareEdges);

    
    struct Subset *subsets = (struct Subset *)malloc(n * sizeof(struct Subset));

    
    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    
    while (i < n - 1 && j < e) {
        
        struct Edge next_edge = edges[j++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[i++] = next_edge;
            Union(subsets, x, y);
        }
    }

    
    printf("Edge   Weight\n");
    for (int i = 0; i < n - 1; i++)
        printf("%d - %d    %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

int main() {
    int n, e;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &e);

    struct Edge edges[E];

    printf("Enter the edges (source destination weight) of the graph:\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    
    kruskalMST(edges, n, e);

    return 0;
}



// testcase
// Enter the number of vertices in the graph: 6
// Enter the number of edges in the graph: 9
// Enter the edges (source destination weight) of the graph:
// 0 1 2
// 0 2 3
// 1 2 5
// 1 3 6
// 2 3 8
// 2 4 7
// 3 4 9
// 3 5 10
// 4 5 1
// Edge   Weight
// 4 - 5    1
// 0 - 1    2
// 0 - 2    3
// 1 - 3    6
// 2 - 4    7