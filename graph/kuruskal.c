#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

void addEdgeMatrix(int from, int to,int weight) {
    adjacencyMatrix[from][to] = weight;
    adjacencyMatrix[to][from] = weight;  // Assuming undirected graph
}

void displayMatrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

struct Edge {
    int src, dest, weight;
};

struct DisjointSet {
    int *parent, *rank;
    int n;
};

struct DisjointSet* createSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));
    set->n = n;

    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }

    return set;
}

int findSet(struct DisjointSet* set, int i) {
    if (i != set->parent[i])
        set->parent[i] = findSet(set, set->parent[i]); // Path compression
    return set->parent[i];
}

void unionSets(struct DisjointSet* set, int x, int y) {
    int rootX = findSet(set, x);
    int rootY = findSet(set, y);

    if (set->rank[rootX] < set->rank[rootY])  // merging two set according to their weight
        set->parent[rootX] = rootY;
    else if (set->rank[rootX] > set->rank[rootY])
        set->parent[rootY] = rootX;
    else {
        set->parent[rootY] = rootX;
        set->rank[rootX]++;
    }
}

void kruskal(int V, int graph[V][V]) {
    struct Edge* edges = (struct Edge*)malloc((V * V) * sizeof(struct Edge));
    int edgeCount = 0;

    // strouing edge in the edge structure
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) { // the i+1 is use for same cycle
            if (graph[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

// sorting the edge acording two edge weight using bubble sort
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    struct DisjointSet* set = createSet(V);
    int mstWeight = 0;

    printf("Minimum Spanning Tree:\n");

    for (int i = 0; i < edgeCount; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        int setSrc = findSet(set, src); // stroing the apselute parent
        int setDest = findSet(set, dest);

        if (setSrc != setDest) { // their apselute root is defarent so we can join
            printf("%d -- %d => %d\n", src, dest, weight);
            mstWeight += weight;
            unionSets(set, setSrc, setDest);
        }
    }

    printf("Total Weight of Minimum Spanning Tree: %d\n", mstWeight);
}

int main() {
    int V = 5;

    int graph[5][5] ;
    //     int vertices =sizeof(graph)/sizeof(graph[0]);
    //     printf("%d",vertices);
    // primMST(graph);
 int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
        for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (from to weight): \n");
    for (int i = 0; i < edges; i++) {
        int from, to,weight;
        scanf("%d %d %d", &from, &to,&weight);

        // Add edges to the graph
        addEdgeMatrix(from, to, weight);
       
    }

    printf("\nAdjacency Matrix:\n");
    displayMatrix(vertices);
     for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
           graph[i][j]=adjacencyMatrix[i][j];
        }
       
    }
    kruskal(V, graph);

    return 0;
}
