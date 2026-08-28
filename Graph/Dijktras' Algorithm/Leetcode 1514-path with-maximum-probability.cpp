
/* 1514 path with maximum probability
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b
 with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

constraints :
2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
*/
class Solution
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node)
    {

        vector<vector<pair<int,double>>> graph(n);
        for(auto i=0 ; i<edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        vector<double> ans(n, 0.0);
        priority_queue<pair<double, int>> pq;
        ans[start_node] = 1.0;
        pq.push({ans[start_node], start_node});

        while(!pq.empty())
        {
            double p = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto [v, w] : graph[u])
            {
                if(ans[v] < ans[u] * w)
                {
                    ans[v] = ans[u] * w;
                    pq.push({ans[v], v});
                }

            }
        }
        return ans[end_node];
    }
};

/*
Example 1:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
.
Example 2:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000

*/
