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
    int n , k;
    cin >> n >> k;
    int a[n+1];
    for(int i = 0;i<n;i++)
        cin >> a[i];
    sort(a, a+ n);
    cout << a[k-1];
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