#include<bits/stdc++.h>
using namespace std;

vector<int> dijktras(int src , vector<vector<pair<int , int>>> & graph)
{
    int n = graph.size();
    vector<int> dist(n , INT_MAX);
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
    dist[src] = 0;
    pq.push({0 , src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : graph[u])
        {
            int v =  edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v] , v);
            }
        }
    }

    return dist;
}


int main()
{
    int vertex , e;
    cin >> vertex >> e;
    vector<vector<pair<int , int>>> graph(vertex);

    for(int i=0 ; i<e ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v , w});
    }
    vector<int> shrtDist ;

    shrtDist = dijktras(0 , graph);

    for(auto x : shrtDist) cout << x << " ";

    return 0;
}

/*
sample input :
6 9
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 4 2
3 5 6
4 5 3

sample output :
0 4 2 9 11 14
*/
