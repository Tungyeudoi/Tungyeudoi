#include <bits/stdc++.h>

using namespace std;
int f[111][111];
int m,n;

void solve(){

    cin >> m >> n;
    int a[m+3][n+3];
    for(int i = 1;i<=m;++i)
        for(int j = 1;j<=n;++j)
        cin >> a[i][j];

    for(int i = 0;i<=n+1;++i)
    {
         f[0][i] = INF;
         f[m+1][i] = INF;
    }

    for(int i = 0;i<=m+1;++i)
    {
         f[i][0] = INF;
         f[i][n+1] = INF;
    }

    for(int i = 1;i<=m;++i)
        f[i][1] = a[i][1];

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}

