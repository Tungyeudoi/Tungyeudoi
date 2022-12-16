#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define ll long long
#define el '\n'
#define all(x) x.begin(),x.end()
#define len(a) a.length()
#define io freopen("input.inp", "r", stdin);freopen("output.out", "w", stdout);
 
using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w1;
    cin >> n >> w1;
    vector<ll> dp(w1+1);
    int w[n+1], v[n+1];

    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = w1; j >= w[i]; --j) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    }

    cout << dp[w1] << el;
    return 0;
}
