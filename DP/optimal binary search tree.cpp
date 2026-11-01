#include<bits/stdc++.h>
using namespace std;
int sum(vector<int>& freq , int i , int j)
{
    int ans = 0;
    for(int k=i ; k<=j ; k++)
        ans += freq[k] ;
    return ans ;
}
int OBST(vector<int>&freq ,int i ,int j)
{
    if(i > j) return 0;
    if(i == j) return freq[i] ;
    int cost = INT_MAX ;
    for(int r=i ; r<=j ; r++)
    {
        cost = min(cost , OBST(freq , i , r-1) + OBST(freq , r+1 , j) + sum(freq ,i , j)) ;
    }
    return cost ;
}
int main()
{
    int n;
    cin >> n ;
    vector<int> a(n) , freq(n) ;
    for(int i=0 ; i<n ; i++)
        cin >> a[i] ;
    for(int i=0 ; i<n ; i++)
        cin >> freq[i] ;
    cout << OBST(freq , 0 , n-1) ;
    return 0;
}
