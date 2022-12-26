#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

const int N = 5e4 + 10;
const int INF = 1e18 + 11;

struct segtree{
    int ma;
    int mi;
};

segtree T[N*4];
int n , q , a[N];


segtree combine(segtree l , segtree r){
    return{
        max(l.ma , r.ma) ,
        min(l.mi , r.mi)
    };
}

void build(int node, int l, int r){
    if(l == r){
        T[node] = {a[l] , a[r]};
        return;
    }

    int mid = (l + r) / 2;
    build(node*2 , l , mid);
    build(node*2+1, mid + 1 , r);
    T[node] = combine(T[node*2], T[node*2+1]);
}


int get_max(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -INF;
    }
    if (u <= l && r <= v) {
        return T[id].ma;
    }
    int mid = (l + r) / 2;

    return max(get_max(id*2, l, mid, u, v), get_max(id*2 + 1, mid+1, r, u, v));
}

int get_min(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return INF;
    }
    if (u <= l && r <= v) {
        return T[id].mi;
    }
    int mid = (l + r) / 2;

    return min(get_min(id*2, l, mid, u, v), get_min(id*2 + 1, mid+1, r, u, v));
}

void solve()
{
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    build(1 , 1 , n);
     while(q--){
        int l , r;
        cin >> l >> r;
        cout << get_max(1 , 1 , n , l , r) - get_min(1 , 1 , n , l , r) << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int q = 1;//cin >> q;
    while(q--) 
      solve();

}
