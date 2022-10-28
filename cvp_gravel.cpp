//author : Le Trong Tung
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100010;
const int INF = 1e9 + 10;
int T[4*N] , lazy[4*N] , a[N] , ss;

void build(int id, int l, int r){
        if(l == r){
            T[id] = ss;
            return;
        }
    
        int mid = (l + r) / 2;
    
        build(id*2 , l , mid);
        build(id*2+1, mid + 1 , r);
    
        T[id] = T[id*2] + T[id*2+1];
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
    
        T[id] = T[id * 2] + T[id * 2 + 1];
}

int get(int id , int l , int r , int u , int v){
        if(l > v || r < u)
            return 0;
        if(u <= l && r <= v)
            return T[id];
    
        lazy_update(id);
    
        int mid = (l + r) / 2;
        return get(id * 2 , l , mid , u , v) + get(id * 2 + 1 , mid + 1 , r , u , v);
}

void solve(){
        int n , m;
    
        cin >> n >> m >> ss;
        build(1 , 1 , n);
        while(m--){
            string key;
            int b , c , k;
            cin >> key;
            if(key == "S"){
                cin >> b >> c >> k;
                update(1 , 1 , n , b , c , k);
            }
            else{
                cin >> b;
                cout << get(1 , 1 , n , b , b) << endl;
            }
        }
}

int32_t main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
            solve();
}
