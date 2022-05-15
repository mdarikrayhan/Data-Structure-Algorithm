#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges, flag = 0, source;
    cin >> nodes;
    cin >> edges;
    list<pair<int, int>> graph[nodes];
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    cin >> source;
    int dist[nodes];
    for (int i = 0; i < nodes; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int i = 0; i < nodes - 1; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            list<pair<int, int>>::iterator x;
            for (x = graph[j].begin(); x != graph[j].end(); ++x)
            {
                int u = j;
                int v = (*x).first;
                int weight = (*x).second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        list<pair<int, int>>::iterator x;
        for (x = graph[i].begin(); x != graph[i].end(); ++x)
        {
            int u = i;
            int v = (*x).first;
            int weight = (*x).second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                flag = 1;
                break;
            }
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