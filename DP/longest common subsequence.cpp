#include<bits/stdc++.h>
using namespace std;
int LCS(string a, string b, int n, int m)
{
    if(m == 0 || n == 0) return 0;
    if(a[n-1] == b[m-1])
    {
        return 1+LCS(a, b, n-1, m-1);
    }
    else return max(LCS(a , b, n-1 , m) , LCS(a, b, n , m-1)) ;
}
int main()
{
    string a,b;
    cin >> a >> b ;
    int n = a.size();
    int m = b.size();
    cout << LCS(a, b , n , m) << endl;
    return 0;
}
