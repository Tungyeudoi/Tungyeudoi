#include <bits/stdc++.h>
using namespace std;

int n,res = -1e9;
int a[100001], f1[100001], f2[100001],g[100001];
void make( int a[], int f[]) {
    int ng = 0;
    for(int i=0;i<n;++i) {
        int id = lower_bound( g, g + ng, a[i]) - g;
        if(id == ng) ++ng;
        g[id] = a[i];
        f[i] = ng;
    }
}

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];
    make(a,f1);
    reverse(a,a+n);
    make(a,f2);
   
    for(int i=0;i<n;++i) 
        res = max(res,min(f2[i],f1[n-i-1])*2-1);
    cout << res << endl;
}
