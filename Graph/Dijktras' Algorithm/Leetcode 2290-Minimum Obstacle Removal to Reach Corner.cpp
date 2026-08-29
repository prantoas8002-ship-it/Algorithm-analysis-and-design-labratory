/*
2290 Minimum Obstacle Removal to Reach Corner
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.
Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
contraints :
m == grid.length
n == grid[i].length
1 <= m, n <= 105
2 <= m * n <= 105
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0
*/
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<pair<int , int>>> graph(row * col);
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                int u = i * col + j;
                if(j-1 >= 0){
                    int v =  i * col + (j-1);
                    int w =  grid[i][j];
                    graph[u].push_back({v , w});
                }
                if(j+1 < col){
                    int v =  i * col + (j+1);
                    int w =  grid[i][j];
                    graph[u].push_back({v , w});
                }
                if(i-1 >= 0){
                     int v =  (i-1) * col + j;
                    int w =  grid[i][j];
                    graph[u].push_back({v , w});
                }
                if(i+1 < row){
                    int v =  (i+1) * col + j;
                    int w =  grid[i][j];
                    graph[u].push_back({v , w});
                }
            }
        }
        vector<int> dist(row * col , 1e6);
        dist[0] = 0;
        priority_queue<pair<int , int> , vector<pair<int ,int>> , greater<pair<int , int>>> pq;
        pq.push({dist[0] , 0});
        while(!pq.empty())
        {
            auto [d , u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;

            for(auto [v , w] : graph[u])
            {
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w ;
                    pq.push({dist[v] , v});
                }
            }
        }

        return dist[row * col - 1];
    }
};

/*
Example 1:
Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
Output: 2

Example 2:
Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
Output: 0
*/

