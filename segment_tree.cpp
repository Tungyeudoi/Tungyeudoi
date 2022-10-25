//author : Le Trong Tung
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define End cout << '\n';
#define con continue;

using namespace std;

const int N = 100010;
const int INF = 1e9 + 10;
int T[4*N] , a[N];

void build(int node, int l, int r){
    if(l == r){
        T[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(node*2 , l , mid);
    build(node*2+1, mid + 1 , r);
    T[node] = max(T[node*2], T[node*2+1]);
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

    T[id] = max(T[id*2], T[id*2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -INF;
    }
    if (u <= l && r <= v) {
        return T[id];
    }
    int mid = (l + r) / 2;

    return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
}

void solve(){
    int n, q;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    cin >> q;
    build(1 , 1 , n);
    while(q--){
        int key , b , c;
        cin >> key >> b >> c;
        if(key == 1){
            update(1 , 1 , n , b , c);
        }
        else{
            cout << get(1 , 1 , n , b , c) << endl;
        }
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
