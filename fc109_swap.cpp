#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e6 + 10;
const int INF = 1e18 + 10;
const int MOD = 1e9 + 7;
int n , q;
int T[4 * N + 6] , a[N];

void build(int node, int l, int r){
    if(l == r){
        T[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(node*2 , l , mid);
    build(node*2+1, mid + 1 , r);
    T[node] = T[node*2] +  T[node*2+1];
}


void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) {
            return ;
        }
        if (l == r) {
            T[id] = v;
            return ;
        }

        int mid = (l + r) / 2;
        update(id*2, l, mid, i, v);
        update(id*2 + 1, mid+1, r, i, v);

        T[id] = T[id*2] + T[id*2 + 1];
}

int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) {
            return 0;
        }
        if (u <= l && r <= v) {
            return T[id];
        }
        int mid = (l + r) / 2;

        return get(id*2, l, mid, u, v) + get(id*2 + 1, mid+1, r, u, v);
}

void solve(){

    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    build(1 , 1 , n);
    while(q--){
        int k , u , v;
        cin >> k >> u >> v;
        if(k == 0){
            int au = a[u] , av = a[v];
            update(1 , 1 , n , v , au);
            update(1 , 1 , n , u , av);
            swap(a[u], a[v]);
         }
         else{
            cout << get(1 , 1 , n , u , v)  << endl;
         }
    }
}


int32_t main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
            solve();
}
