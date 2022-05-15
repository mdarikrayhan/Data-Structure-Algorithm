#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges, src, flag = 0;
    // cout<<"Enter the numer of nodes and edges : ";
    cin >> nodes >> edges;
    vector<int> edge[edges];
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].push_back(u);
        edge[i].push_back(v);
        edge[i].push_back(w);
    }
    cin >> src;
    int dist[nodes];
    for (int i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for (int i = 0; i < nodes-1; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int u = edge[j][0];
            int v = edge[j][1];
            int weight = edge[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < edges; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        int weight = edge[i][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < nodes; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }
    else
    {
        printf("Graph contains negative weight cycle");
    }
    return 0;
}