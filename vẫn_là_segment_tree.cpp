#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50111;
struct Node {
    int lazy; // giá trị T trong phân tích trên
    int val; // giá trị lớn nhất
} nodes[MAXN * 4];

void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;
    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;
    nodes[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -2000111000;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id);

    return max(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
}

int main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) {
            int l, r, val; cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else {
            int l, r; cin >> l >> r;
            cout << get(1,1,n,l,r) << "\n";
        }
    }
}
