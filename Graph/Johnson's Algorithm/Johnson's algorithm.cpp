
#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<pair<int, int>>>& graph, int n, int src)
{
    vector<int> dist(n, 1000);
    dist[src] = 0;
    for(int i=0 ; i<n-1 ; i++)
    {
        for(int u=0 ; u<n ; u++)
        {
            for(auto edge : graph[u])
            {
                int v = edge.first;
                int w = edge.second;

                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    return dist;
}


// dijktras algorithm

vector<int> dijktras(vector<vector<pair<int, int>>>& graph, int n, int src )
{
    vector<int> dist(n, 1000);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();


        for(auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w ;
                pq.push({dist[v], v});
            }
        }
    }
     return dist;
}

int main()
{
    int v = 4;

    vector<vector<int>> edgeList =
    {
        {0, 1, -5},
        {0, 2, 2},
        {0, 3, 3},
        {1, 2, 4},
        {2, 3, 1}
    };
    vector<vector<pair<int,int>>> graph(v+1);

    for(int i=0 ; i<edgeList.size() ; i++)
    {

        graph[edgeList[i][0]].push_back({edgeList[i][1], edgeList[i][2]});

    }

    for(int i=0 ; i<v ; i++)
    {
        graph[v].push_back({i,0});
    }


    vector<int> bellmanDist = bellmanFord(graph, v+1, 4);


// making all the edges non negative
    for(int u =0 ; u<v ; u++)
    {
        for(auto &edge : graph[u])
        {
            int v = edge.first;
            // cout << v << " " << edge.second << endl;
            edge.second = edge.second + bellmanDist[u] - bellmanDist[v];
           //  cout << v << " " << edge.second << endl;
        }
    }

    vector<vector<int>> johnsonDistMatrix;

    for(int src = 0 ; src < v ; src++)
    {
        auto sample = dijktras(graph , v , src);
        for(int i=0 ; i<v ; i++)
        {
            if(sample[i] == 1000) continue;
            sample[i] = sample[i] + bellmanDist[i] - bellmanDist[src] ;
        }
        johnsonDistMatrix.push_back(sample);
    }


    //printing bellman dist

    // for(auto x : bellmanDist) cout << x << " ";


    // printing the shortest johnson matrix

    for(auto x : johnsonDistMatrix)
    {
        for(int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }


    //print the graph
    /*
    for(int u=0 ; u<=v ; u++)
    {
        cout << u << ": ";
        for(auto edge : graph[u])
        {
            cout << edge.first << "," << edge.second << " ";
        }
        cout << endl;
    }
    */


    return 0;
}
