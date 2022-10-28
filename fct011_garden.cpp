#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e18 + 10;
const int MOD = 1e9 + 7;
int n , X;
pair <int , int> v[N];
bool check(int s){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        int a , b;
        a = v[i].fi;
        b = v[i].se;
        if(cnt > X) return 0;
        if(a > s) continue;
        cnt += (s - a + b - 1)/ b;
    }
    return cnt <= X;

}

void solve(){
    int l = INF, r = INF;
    cin >> n >> X;
    for(int i = 0;i<n;i++){
        cin >> v[i].fi >> v[i].se;
        l = min(l , v[i].fi);
    }
    sort(v , v + n);

    while(l <= r){
        int mid = l + (r - l + 1)/2;
        if(check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1;
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
