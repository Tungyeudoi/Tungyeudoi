#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int N = 1e5 + 3;
const int INF = 1e18 + 10;



void solve(){
    int n , res = -INF;
    cin >> n;
    int a[N] , f[N][2];
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        res = max(a[i],res);
    }

    f[1][0] = f[1][1] = a[1];
    f[2][1] = a[1] + a[2];
    f[2][0] = a[2];

    for(int i = 3;i<=n;i++){
        f[i][1] = f[i-1][0] + a[i];
        f[i][0] = max(f[i-2][0], f[i-2][1]) + a[i];
        
    }
    for(int i = 1;i<=n;i++){
        res = max(res, max(f[i][1], f[i][0]));
    }
    cout << max(0LL,res);


}


int32_t main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int q = 1;
            //cin >> q;
        while(q--)
            solve();
}
        //#define TASK ""
        //freopen("TASK.inp","r",stdin);
        //freopen("TASK.out","w",stdout);
