#include <bits/stdc++.h>
using namespace std;
int visited[100] = {0};
vector<int> adj[100];
void DFS(int u)
{
    visited[u] = 1;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (visited[adj[u][i]] == 0)
        {
            DFS(adj[u][i]);
        }
    }
}
int main()
{
    int n, edge, node1, node2;
    cout << "Enter the node:";
    cin >> n;
    cout << "Enter the edge:";
    cin >> edge;
    set<int> s;
    set<int>::iterator itr;
    for (int i = 0; i < edge; i++)
    {
        cin >> node1 >> node2;
        s.insert(node1);
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        if (visited[*itr] == 0)
        {
            DFS(*itr);
        }
    }
    return 0;
}