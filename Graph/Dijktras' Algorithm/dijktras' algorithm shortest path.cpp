#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex, edge;
    cin >> vertex >> edge ;

    vector<vector<pair<int, int>>> graph(vertex);

    for(int i=0 ; i<edge ; i++)
    {
        int u,v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // dijktras logic
    int src = 0;

    vector<int> dist(vertex, 1e6);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({dist[src],src});
    vector<int> parent(vertex, -1);
    vector<int> path;

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v],  v});
            }
        }

    }

    int destination;
    cin >> destination;

    //src to destination path

    // path.push_back(destination);
    while(destination != -1)
    {
        path.push_back(destination);
        destination = parent[destination];
    }

    reverse(path.begin(), path.end());


    // printing the shortest vector

    for(auto x : dist)  cout << x << " ";

    cout << endl;

    //printing the parent list
    for(auto x : parent)  cout << x << " ";

    cout << endl;

    //printing the path
    for(int i=0; i<path.size(); i++)
    {
        cout << path[i];

        if(i + 1 < path.size())
            cout << " -> ";
    }



    return 0;
}

/*
input :
5 6
0 1 4
0 2 8
1 2 3
1 4 6
2 3 2
3 4 10
3
 output :
 0 -> 1 -> 2 -> 3
*/
