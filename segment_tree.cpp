// Test
#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const int N = 1000010;

struct Node {
    int lazy;
    int val;
} nodes[N * 4];



void down(int id){
    int t = nodes[id].lazy;

    nodes[2 * id].lazy += t;
    nodes[2 * id].val += t;

    nodes[2 * id + 1].lazy += t;
    nodes[2 * id + 1].val += t;

    nodes[id].lazy = 0;
}

void update(int id , int l , int r , int u , int v , int val){
    if(r < u || l > v) return ;

    if(u <= l && r <= v){
        nodes[id].val = nodes[id].val + val;
        nodes[id].lazy = nodes[id].lazy + val;
        return ;
    }

    int mid = (l + r) / 2;

    down(id);

    update(id * 2 , l , mid , u , v , val);
    update(id * 2 + 1, mid + 1 , r , u , v , val);

}

int get(int id , int l , int r , int u , int v){
    if(v < l || r < u) return -1;

    if(u <= l && r <= v){
        return nodes[id].val;
    }

    down(id);
    int mid = (l + r) / 2;

    return max(get(id * 2 , l , mid , u , v) ,
               get(id * 2 + 1 , mid + 1 , r , u , v));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;

    update(1 , 1 , n , 1 , n , c);
    for(int i = 1;i <= m;i ++){
        int u , v , k , p;
        char luf ;
        cin >> luf ;

        if(luf == 'S'){
            cin >> u >> v >> k;

            update(1 , 1 , n , u , v , k);
        } else {

            cin >> p;

            cout << get(1 , 1 , n , p , p) << '\n';
        }
    }

    return 0;
}
