#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>>&residugraph, int &src, int &dst, vector<int>&parent)
{
    int n = residugraph.size() - 1 ;
    vector<bool> vis(n+1, false);
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v=1 ; v<=n ; v++)
        {
            if(!vis[v] && residugraph[u][v] > 0)
            {
                vis[v] = true;
                parent[v] = u ;

                if(v == dst) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int main()
{
    int vertex;
    cin >> vertex;
    int edge;
    cin >> edge ;
    vector<vector<int>> residugraph(vertex+1, vector<int>(vertex+1, 0));
    for(int i=1 ; i<=edge ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w ;
        residugraph[u][v] = w ;
    }

    // residue graph = capacity graphs
    //logic
    int src = 1;
    int dst = vertex ;
    vector<int> parent(vertex +1);
    int maxflow = 0;
    while(bfs(residugraph, src, dst, parent))
    {
        int pathflow = INT_MAX;

        for(int v = dst ; v != src ; v = parent[v])
        {
            int u = parent[v] ;
            pathflow = min(pathflow, residugraph[u][v]);
        }


        for(int v = dst ; v != src ; v = parent[v])
        {
            int u = parent[v] ;
            residugraph[u][v] -= pathflow;
            residugraph[v][u] += pathflow;
        }

        maxflow += pathflow ;

    }


//printing
    for(int u=1 ; u<=vertex ; u++)
    {
        for(int v=1 ; v<=vertex ; v++)
        {
            cout << residugraph[u][v] << " ";
        }
        cout << endl;
    }

    cout << maxflow << endl;

    return 0;
}
/*
6
9
1 2 10
2 3 4
3 6 10
1 4 10
4 5 9
5 6 10
2 4 2
2 5 8
5 3 6
*/
