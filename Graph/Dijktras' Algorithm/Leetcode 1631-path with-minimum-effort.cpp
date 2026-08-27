
/*
Path With Minimum Effort
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed).
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Constraints :
rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106
*/

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<pair<int,int>>> graph(row * col);
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                int u = i * col + j ;

                if(j+1 < col)
                {
                    int v = i * col + (j+1);
                    graph[u].push_back({v, abs(heights[i][j] - heights[i][j+1])});
                }
                if(j-1 >= 0)
                {
                    int v = i * col + (j-1);
                    graph[u].push_back({v, abs(heights[i][j] - heights[i][j-1])});
                }

                if(i+1 < row)
                {
                    int v = (i+1) * col + j;
                    graph[u].push_back({v, abs(heights[i][j] - heights[i+1][j])});
                }
                if(i-1 >= 0)
                {
                    int v = (i-1) * col + j;
                    graph[u].push_back({v, abs(heights[i][j] - heights[i-1][j])});
                }
            }
        }

        vector<int> dist(row * col, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({dist[0], 0});

        while(!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto [v, w] : graph[u])
            {
                if(dist[v] > max(dist[u], w))
                {
                    dist[v] = max(dist[u], w);
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[row*col - 1];
    }
};

/*
Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
*/

