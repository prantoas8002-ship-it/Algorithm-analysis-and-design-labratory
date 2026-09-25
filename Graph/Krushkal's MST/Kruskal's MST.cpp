#include<bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> parent;
    vector<int> rnk;
    DSU(int v)
    {
        parent.resize(v);
        rnk.resize(v);

        for(int i=0 ; i<v ; i++)
        {
            parent[i] = i ;
            rnk[i] = 1;
        }
    }

    int found(int x)
    {
        return parent[x] == x ? x : parent[x] = found(parent[x]);
    }

    void Union(int x, int y)
    {
        int s1 = found(x);
        int s2 = found(y);

        if(rnk[s1] < rnk[s2])
        {
            parent[s1] = s2;
        }
        else if(rnk[s1] > rnk[s2])
        {
            parent[s2] = s1;
        }
        else
        {
            parent[s2] = s1;
            rnk[s1]++;
        }
    }
};

bool comparator(vector<int>x, vector<int> y)
{
    return x[2] < y[2];
}
int main()
{
    int vertex ;
    cin >> vertex ;
    int edge;
    cin >> edge;
    vector<vector<int>> graphList(edge, vector<int>(3));
    for(int i=0 ; i<edge ; i++)
    {
        int u, v, w ;
        cin >> u >> v >> w ;
        graphList[i][0] = u;
        graphList[i][1] = v;
        graphList[i][2] = w;
    }
    DSU dsu(vertex);
    sort(graphList.begin(), graphList.end(), comparator);
    int cost = 0;
    int Count = 0;
    for(int i=0 ; i<edge ; i++)
    {
        int u = graphList[i][0] ;
        int v = graphList[i][1] ;
        int w = graphList[i][2] ;

        if(dsu.found(u) != dsu.found(v))
        {
            cost += w;
            dsu.Union(u, v);
            Count++;

            if(Count == vertex -1) break;
        }
    }

    cout << cost << endl;
    return 0;
}
/*
4
5
0 1 10
1 3 15
2 3 4
2 0 6
0 3 5
*/
