#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e18 + 10;
const int MOD = 1e9 + 7;



void solve(){
    int n , res = INF;
    pair<int, int> a[2*N];
    cin >> n;
    for(int i = 0; i < 2*n; ++i) {
        cin >> a[i].first;
        if (i < n)
            a[i].second = 0;
        else
            a[i].second = 1;
    }

    sort(a , a + 2 * n);
    int ans = INF;
    for(int i = 1;i<2*n;i++)
        if (a[i].second + a[i-1].second == 1)
            res = min(res, a[i].fi - a[i-1].fi);

    cout << res;

}


int32_t main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int q = 1;
           // cin >> q;
        while(q--)
            solve();
}
        //#define TASK ""
        //freopen("TASK.inp","r",stdin);
        //freopen("TASK.out","w",stdout);
