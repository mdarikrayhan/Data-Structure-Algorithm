#include <iostream>
#include <vector>
#include <set>
#include <list>
using namespace std;
vector<pair<pair<string, string>, pair<int, int> > > graph;
void print_graph()
{
    for(int i=0;i<graph.size();i++)
    {
         cout<<graph[i].first.first<<" "<<graph[i].first.second<<" "<<graph[i].second.first<<" "<<graph[i].second.second<<endl;
    }
}
void add_edge()
{
    int stop = 1;
    while (stop==1)
    {
        string u, v;
        int cost,dist;
        cin >> u >> v >> cost>>dist;
        graph.push_back(make_pair(make_pair(u, v),make_pair(cost, dist)));
        cout<<"Do you want to add more edges? 1.Yes 2.No"<<endl;
        cin>>stop;
    }
}
int main()
{
    add_edge();
    print_graph();
    return 0;
}