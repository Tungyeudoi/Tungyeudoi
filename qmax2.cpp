#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define End cout << '\n';
#define con continue;

using namespace std;

const int N = 100010;
const int INF = 1e9 + 10;
int T[4*N] , lazy[4*N] , a[N];

void build(int id, int l, int r){
    if(l == r){
        T[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(id*2 , l , mid);
    build(id*2+1, mid + 1 , r);

    T[id] = max(T[id*2] , T[id*2+1]);
}

void lazy_update(int id){
    int x = lazy[id];
    T[id * 2] += x;
    lazy[id * 2] += x;

    T[id * 2 + 1] += x;
    lazy[id * 2 + 1] += x;

    lazy[id] = 0;
}

void update(int id , int l , int r , int u , int v, int val){
    if(l > v || r < u)
        return;
    if(u <= l && r <= v){
        T[id] += val;
        lazy[id] += val;
        return;
    }

    lazy_update(id);

    int mid = (l + r) / 2;
    update(id * 2 , l , mid , u , v , val);
    update(id * 2 + 1 , mid + 1 , r , u , v , val);

    T[id] = max(T[id * 2] , T[id * 2 + 1]);
}

int get(int id , int l , int r , int u , int v){
    if(l > v || r < u)
        return -INF;
    if(u <= l && r <= v)
        return T[id];

    lazy_update(id);

    int mid = (l + r) / 2;
    return max(get(id * 2 , l , mid , u , v) ,get(id * 2 + 1 , mid + 1 , r , u , v));
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        a[i] = 0;
    }

    build(1 , 1 , n);
    while(q--){
        int key , b , c;
        cin >> key;
        if(key == 0){
            int x , y , k;
            cin >> x >> y >> k;
            update(1 , 1 , n , x , y, k);
        }
        else{
            int l , r;
            cin >> l >> r;
            cout << get(1 , 1 , n , l , r) << endl;
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
