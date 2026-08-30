/*
1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n , vector<int>(n,1e6));
        for(int i=0 ; i<edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for(int i=0 ; i<n ; i++)
        {
          dist[i][i] = 0;
        }

        for(int k=0 ; k<n ; k++)
        {
            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<n ; j++)
                {
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j] ;
                    }
                }
            }
        }

       vector<pair<int , int>> ansPair;
        int min = INT_MAX;
        for(int i=0 ; i<n ; i++)
        {
            int count = 0;
            for(int j=0 ; j<n ; j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if(min > count - 1) min = count - 1;
            ansPair.push_back({i , count - 1});
        }

        int ans;
        for(int i= n-1 ; i>=0 ; i--)
        {
            if(ansPair[i].second == min){
                ans = ansPair[i].first;
                break;
            }
        }
        return ans;
    }
};

/*
Example 1:
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3

Example 2:
Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
*/
