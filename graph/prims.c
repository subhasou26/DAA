#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph
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

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) { // ==0 mean not visited
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int parent[V]; // parent child
    int key[V];    // distance array

    int mstSet[V]; // what node include in mst

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0; // source value
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) { // non visited and minimum weight 
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
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
    primMST(graph);


    return 0;
}
