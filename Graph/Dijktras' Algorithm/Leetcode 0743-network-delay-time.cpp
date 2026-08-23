
/*743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int ,int>>> graph(n+1);

        for(auto x : times)
        {
            graph[x[0]].push_back({x[1] , x[2]});
        }

        priority_queue<pair<int ,int> , vector<pair<int ,int>> , greater<pair<int , int>>> pq;
        vector<int> dist(n+1 , 1000);
        dist[k] = 0;
        pq.emplace(0,k);
        while(!pq.empty())
        {
            int d =  pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u]) continue;

            for(auto edge : graph[u])
            {
                int v = edge.first;
                int w = edge.second;

                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w ;
                    pq.emplace(dist[v] , v);
                }
            }
        }

        int max = INT_MIN;

        for(int i=1 ; i<=n ; i++)
        {
            int x = dist[i];
            if(x == 1000) return -1;
            if(x > max) max = x;
        }
        return max;

    }
};

/*

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 */

