#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex;
    int edge;
    cin >> vertex ;
    cin >> edge;
    vector<vector<int>> graph(vertex);
    for(int i=0 ; i<edge ; i++)
    {
        int u, v;
        cin >> u >> v ;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool vis[vertex] = {false};

    for(int src=0 ; src < vertex ; src++)
    {
        if(vis[src] == true) continue;
        vis[src] = true;
        queue<int> q;
        q.push(src);

        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " " ;
            for(auto v : graph[u])
            {
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    cout << endl;

    //printing graph...
    for(int u=0 ; u<vertex ; u++)
    {
        cout << u << " : ";
        for(int v : graph[u])
            cout << v << " ";
        cout << endl;
    }
    return 0;
}
/*
6
8
0 1
0 2
1 3
1 4
2 4
0 4
3 4
3 5
*/
