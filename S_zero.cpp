#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e2 + 9;
const int INF = 1e18 + 11;
char a[N][N];
int n , m , ans1 = 0 , ans2 = 0;

void solve()
{
    cin >> n >> m;

    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            cin >> a[i][j];
    //Theo hang doc
    for(int j = 1;j<=m;j++){
        int cnt = 0;
        bool flag = 0;
        for(int i = 1;i<n;i++){
            int pos = -1;
            if(a[i][j] == '1' && a[i+1][j] =='0'){
                i++;
                pos = i;
                while(a[i][j] != '1'){if(i==n) break; i++;}
                if(a[i][j]=='1') {cnt += i - pos;i--;}
            }
        }
        ans1+=cnt;
    }
    //Theo hang ngang
    for(int i = 1;i<=n;i++){
        int cnt = 0;
        bool flag = 0;
        for(int j = 1;j<m;j++){
            int pos = -1;
            if(a[i][j] == '1' && a[i][j+1] =='0'){
                j++;
                pos = j;
                while(a[i][j] != '1'){if(j==m) break; j++;}
                if(a[i][j]=='1') {cnt += j - pos;j--;}
            }
        }
        ans2 += cnt;
    }

    cout << min(ans1,ans2);

}
/*
8 8
01000000
10110000
10011100
10000010
10011100
10000100
10101000
01111100
*/

#define taskname ""
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;//cin >> q;
    while(q--) solve();

}

