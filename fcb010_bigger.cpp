#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 3;
const int INF = 1e18 + 10;



void solve(){
    int a, b , ans = 0;
    cin >> a >> b;
    while(a <= b){
        a *= 3;
        b *= 2;
        ans ++;
    }
    cout << ans;
}


int32_t main()
{

        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
            solve();
}
