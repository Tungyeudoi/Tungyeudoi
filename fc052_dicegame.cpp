#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int N = 1e5 + 10;
const int INF = 1e18 + 10;
const int MOD = 1e9 + 7;
int n , q , a[N], f[N];



void solve(){

    cin >> n >> q;
    for(int i = 0;i<n;i++)
        cin >> a[i];
    a[n] = INF;
    stack < int > st;
    st.push(n);
    for (int i = n - 1; i >= 0; i--) {
        while (a[i] >= a[st.top()])
            st.pop();
        f[i] = st.size();
        st.push(i);
    }

    while (q--) {
        int x;
        cin >> x;
        x--;
        cout << f[x] - 1 << '\n';
    }
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
