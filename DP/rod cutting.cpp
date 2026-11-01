#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&price , int n)
{
    if(n == 0) return 0;
    int ans =0;

    for(int i=0 ; i<n ; i++)
    {
        ans = max(ans , price[i] + solve(price , n-i-1));
    }
    return ans ;
}
int main()
{
    int n;
    int m;
    cin >> n >> m ;
    vector<int> price(m);
    for(int i=0 ; i<m ; i++) cin >> price[i] ;
    int ans = solve(price , n);
    cout << ans << endl;
}
