
#include<bits/stdc++.h>
using namespace std;

#define INF 1e4
vector<int> dp(1000 , -1) ;
int soln(vector<int> coin, int amount)
{
    if(amount == 0) return 0;
    else if(amount < 0) return INF;
    else if(dp[amount] != -1)
        return dp[amount] ;

    int ans = INF;

    for(int i = 0; i < coin.size(); i++)
    {
        int res = soln(coin, amount - coin[i]);
        ans = min(ans, 1 + res);
    }

    dp[amount] = ans;

    return dp[amount];
}

int main()
{
    int n;
    cin >> n;

    vector<int> coin(n);

    for(int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    int amount;
    cin >> amount;

    int ans = soln(coin, amount);

    if(ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
