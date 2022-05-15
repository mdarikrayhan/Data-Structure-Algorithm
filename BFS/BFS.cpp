#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    vector<int> adjlist[100];
    vector<int> t;
    int nodes,edge,v, visited[100] = {0}, par[100] = {0}, level[100] = {0};
    
    
    cout << "Enter the node : ";
    cin >> nodes;
    cout << "Enter the edge : ";
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for (int i = 1; i <= nodes; i++)
    {
        cout << i << ":";
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            cout << adjlist[i][j] << " ";
        }
    }


    int source,destination;
    cout << "\nEnter source : ";
    cin >> source;
    cout << "\nEnter destination:";
    cin >> destination;


    queue<int> q;
    visited[source] = 1;
    q.push(source);
    while (!q.empty())
    {
        int element = q.front();
        t.push_back(element);
        q.pop();
        for (int i = 0; i < adjlist[element].size(); i++)
        {
            v = adjlist[element][i];
            if (visited[v] == 0)
            {
                visited[v] = 1;
                q.push(v);
                level[v] = level[element] + 1;
            }
        }
    }


    cout <<"Level : "<< level[destination] << endl;
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << "   ";
    }
}
