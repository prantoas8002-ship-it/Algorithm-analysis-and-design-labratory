 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     int vertex;
     int edge;
     cin >> vertex >> edge;
     vector<vector<pair<int , int>>> graph(vertex);
     for(int i=0 ; i<edge ; i++)
     {
         int u , v , w;
         cin >> u >> v >> w;
         graph[u].push_back({v , w});
         graph[v].push_back({u , w});
     }
     int src = 0;
     vector<bool> vis(vertex , false);
     priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
     pq.push({0, src});
     int mincost = 0;
     while(!pq.empty())
     {
         auto [w , u] = pq.top();
         pq.pop();
         if(vis[u]) continue;

         mincost += w;
         vis[u] = true;

         for(auto [v , w] : graph[u])
         {
             if(!vis[v])
             {
                 pq.push({w , v});
             }
         }

     }
     cout << mincost << endl;
     return 0;
 }
 /*
 6
 9
 0 1 2
 0 4 4
 0 3 1
 1 2 3
 1 3 3
 1 5 7
 3 4 9
 2 5 8
 2 3 5
 */
