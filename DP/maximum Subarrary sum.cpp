#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&a , int i)
{
    if(i == 0) return a[0] ;
    return max(a[i] , a[i] + solve(a , i-1)) ;
}
int main()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++)
    {
        cin >> a[i] ;
    }
    int ans = 0;
    for(int i=0 ; i<n ; i++)
    {
        ans = max(ans , solve(a , i));
    }
    cout << ans << endl;
}
