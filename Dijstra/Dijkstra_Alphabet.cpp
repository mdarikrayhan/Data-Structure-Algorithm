#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges, flag;
    char source;
    // cout << "Enter the number of nodes : ";
    cin >> nodes;
    // cout << "Enter the number of edges : ";
    cin >> edges;
    list<pair<char, int>> graph[nodes+97];
    // cout << "1.Directed" << endl << "2.Undirected" << endl << "Do have Directed Graph or Undirected : ";
    cin >> flag;

    for (int i = 0; i < edges; i++)
    {
        char u,v;
        int w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        if (flag == 2)
        {
            graph[v].push_back(make_pair(u, w));
        }
    }

    // cout<<"Enter the source : ";
    cin >> source;
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
    vector<int> dist(nodes+97, INT_MAX);
    pq.push(make_pair(source, 0));
    dist[source] = 0;
    char parent[nodes+97];
    parent[source] = 0;
    while (!pq.empty())
    {
        char u = pq.top().first;
        pq.pop();
        list<pair<char, int>>::iterator i;
        for (i = graph[u].begin(); i != graph[u].end(); ++i)
        {
            char v = (*i).first;
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
    for (char i = 97; i < nodes+97; ++i)
    {
        printf("%c \t\t %d\n", i, dist[i]);
    }
    //cout<<"Enter the destination :";
    char destination;
    cin>>destination;
    vector<char>path;
    vector<char>::iterator ipath;
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