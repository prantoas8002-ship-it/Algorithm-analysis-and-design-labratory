#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n ;
    vector<vector<int>> dist(n , vector<int>(n));

    // input the distance matrix

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ;  j++)
        {
            cin >> dist[i][j];
        }
    }

    // warshall logic here

    for(int k = 0 ; k<n ; k++)
    {
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }


    // printing the distance matrix

    for(auto x : dist)
    {
        for(auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
input :
5
0 4 1000 5 1000
1000 0 1 1000 6
2 1000 0 3 1000
1000 1000 1 0 2
1 1000 1000 4 0
output :
0 4 5 5 7
3 0 1 4 6
2 6 0 3 5
3 7 1 0 2
1 5 5 4 0

here 1000 means infinity distance
*/
