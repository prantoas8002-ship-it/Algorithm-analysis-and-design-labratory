/*
1976 Number of Ways to Arrive at Destination

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections.
 The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel.
You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

constraints :
1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.
*/

class Solution
{
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int, int>>> graph(n);
        for(auto x : roads)
        {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int >>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto [v, w] : graph[u])
            {
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == dist[u] + w)
                {
                    ways[v] = (ways[v] + ways[u]) % (int)(1e9 + 7);
                }
            }
        }
        return ways[n-1];
    }
};

/*
Example 1:
Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4

Example 2:
Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
*/

