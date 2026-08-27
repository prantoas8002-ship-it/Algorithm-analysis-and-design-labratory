/*
0787-find-chipest-path
There are n cities connected by some number of flights.
 You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
If there is no such route, return -1.

Constraints :
2 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> graph(n);
        for(auto edge : flights)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v , w});
        }
        vector<int> dist(n , 1e6);
        dist[src] = 0;

        for(int step = 0 ; step <= k ; step++)
        {
            vector<int> temp = dist ;

            for(int u = 0 ; u < n ; u++)
            {
                for(auto [v , w] : graph[u])
                {
                    temp[v] = min(temp[v] , dist[u] + w);
                }
            }

            dist = temp;
        }

        if(dist[dst] == 1e6) return -1;
        else return dist[dst];


    }
};

/*
Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
*/
