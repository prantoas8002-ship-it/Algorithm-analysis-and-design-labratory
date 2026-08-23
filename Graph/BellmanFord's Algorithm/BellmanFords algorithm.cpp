#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanford(vector<vector<pair<int, int>>> &graph, int src)
{
    int n = graph.size();
    vector<int> dist( n, 1000);
    dist[src] = 0;

    for (int i = 0; i < n-1; ++i)
    {
        for(int u = 0 ; u< n ; u++)
        {
            for(auto e : graph[u])
            {
                int v = e.first ;
                int w = e.second ;
                if(dist[u]!=1000 && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w ;
                }
            }


        }
    }


    return dist;
}
int main()
{
    int vertex, edge;
    cin >> vertex >> edge ;

    vector<vector<pair<int, int>>> graph(vertex);

    for(int i=0 ; i<edge ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> dist = bellmanford(graph, 0);

    for(auto x : dist)
    {
        cout << x << " ";
    }

    /* for(int u=0 ; u<vertex ; u++)
     {
         cout << u << ": ";
         for(auto e : graph[u])
         {
             cout << e.first << "," << e.second << " ";
         }
         cout << endl;
     }*/

    return 0;
}


/*
5
10
0 1 6
1 2 5
2 1 -2
0 4 7
4 3 9
3 2 7
3 0 2
1 4 8
1 3 -4
4 2 -3
*/

