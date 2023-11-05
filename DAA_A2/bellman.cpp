#include <iostream>

using namespace std;
const int INT_MAX = 999;

class Graph
{
public:
    int src, dest, wt;
};

void bellman(int v, int e, Graph edge[], int srcV)
{
    int mat[v][e];
    int dist[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[srcV] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].wt;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
            // cout << edge[j].wt << " ";
        }
        // cout << endl;
    }

    for (int i = 0; i < e; i++)
    {
        int u = edge[i].src;
        int v = edge[i].dest;
        int w = edge[i].wt;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative cycle present...";
            return;
        }
    }
    cout << "Source"
         << "->"
         << "Destination "
         << ": "
         << "Shortest Distance" << endl;
    for (int i = 0; i < v; i++)
    {
        cout << edge[i].src << "->" << edge[i].dest << ":" << dist[i] << endl;
    }
}

int main()
{
    int v, e;
    cout << "Enter number of vertices:\n";
    cin >> v;
    cout << "Enter number of Edges:\n";
    cin >> e;
    Graph edge[e];
    for (int i = 0; i < e; i++)
    {
        cout << "Enter Source, Destination, and Weight " << i + 1 << ":\n";
        cin >> edge[i].src >> edge[i].dest >> edge[i].wt;
    }
    int srcV;
    cout << "Enter Source Vertex:\n";
    cin >> srcV;

    bellman(v, e, edge, srcV);

    return 0;
}
/*
OUTPUT
Enter number of vertices:
5
Enter number of Edges:
8
Enter Source, Destination, and Weight 1:
0 1 -1
Enter Source, Destination, and Weight 2:
0 2 4
Enter Source, Destination, and Weight 3:
1 2 3
Enter Source, Destination, and Weight 4:
1 3 2
Enter Source, Destination, and Weight 5:
1 4 2
Enter Source, Destination, and Weight 6:
3 2 5
Enter Source, Destination, and Weight 7:
3 1 1
Enter Source, Destination, and Weight 8:
4 3 -3
Enter Source Vertex:
0

Source->Destination : Shortest Distance
0->1:0
0->2:-1
1->2:2
1->3:-2
1->4:1

*/

/* 5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
*/
/*
#include <iostream>
using namespace std;
const int INF = 1e9; // Infinity value for unreachable vertices

void bellmanFord(int graph[100][100], int V, int E, int source) {
    int distance[100];

    // Initialize distances
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
    }

    distance[source] = 0;

    // Relax edges |V-1| times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
            cout<<weight<<" ";
        }
        cout<<endl;
    }

    // Check for negative cycles
    for (int j = 0; j < E; j++) {
        int u = graph[j][0];
        int v = graph[j][1];
        int weight = graph[j][2];
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            std::cout << "Graph contains negative weight cycle!" << std::endl;
            return;
        }
    }

    // Print the shortest distances from the source
    for (int i = 0; i < V; i++) {
        std::cout << "Distance from source to vertex " << i << ": " << distance[i] << std::endl;
    }
}

int main() {
    int V, E;
    std::cout << "Enter the number of vertices (V) and edges (E): ";
    std::cin >> V >> E;

    int graph[100][100];

    std::cout << "Enter the edges (u, v, weight):" << std::endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = weight;
    }

    int source;
    std::cout << "Enter the source vertex: ";
    std::cin >> source;

    bellmanFord(graph, V, E, source);

    return 0;
}
*/
