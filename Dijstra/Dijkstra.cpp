#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges, flag, source;
    // cout << "Enter the number of nodes : ";
    cin >> nodes;
    // cout << "Enter the number of edges : ";
    cin >> edges;
    list<pair<int, int>> graph[nodes];
    // cout << "1.Directed" << endl << "2.Undirected" << endl << "Do have Directed Graph or Undirected : ";
    cin >> flag;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        if (flag == 2)
        {
            graph[v].push_back(make_pair(u, w));
        }
    }

    // cout<<"Enter the source : ";
    cin >> source;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(nodes, INT_MAX);
    pq.push(make_pair(source, 0));
    dist[source] = 0;
    int parent[nodes];
    parent[source] = 0;
    while (!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = graph[u].begin(); i != graph[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(v,dist[v]));
            }
        }
    }

    printf("Nodes Distance from Source\n");
    for (int i = 0; i < nodes; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
    //cout<<"Enter the destination :";
    int destination;
    cin>>destination;
    vector<int>path;
    vector<int>::iterator ipath;
    while(destination!=source){
        path.push_back(destination);
        destination=parent[destination];
    }
    path.push_back(source);
    reverse(path.begin(),path.end());
    cout<<"The path is : ";
    for(ipath=path.begin();ipath<path.end();ipath++){
        cout<<*ipath;
        if(ipath!=path.end()-1){
            cout<<"->";
        }
    }
    return 0;
}