#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define End cout << '\n';
#define con continue;

using namespace std;

const int N = 100010;
const int INF = 1e9 + 10;


void solve(){
    int f[10]; f[0] = 1;
    for(int i = 1;i<=9;i++)
        f[i] = f[i-1] * i;

    int n; cin >> n;
    if(n == 1){
        cout << 0; return;
    }
    vector<int> ans;
    while(n > 0){
        int c = 0;
        while(c < 9 && f[c+1] <= n) c++;
        ans.push_back(c);
        n -= f[c];
    }
    sort(ans.begin(),ans.end());
    for(auto x : ans) cout << x;


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
