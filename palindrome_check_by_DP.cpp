#include <bits/stdc++.h>
//#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define int long long
#define FOR(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

const int N = 1e7 + 11;
const int INF = 1e18 + 11;
const int lim_inf = 1e7 + 11;

bool a[1001][1001];
bool dx[300][300];
void solve()
{
    string s;
    cin >> s;
    int cnt = 0 , n = s.size() ;
    //s = s;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<=n-1-i;j++)
        {
            if(i==0) a[j][j]= true;
            else if(i==1)
            {
                if(s[j]==s[j+1]) a[j][j+1]=true;
                else a[j][j+1]= false;
            }
            else
            {
                 if(s[j]!=s[j+i]) a[j][j+i]=false;
                 else  a[j][j+i]=a[j+1][j+i-1];
            }
        }
    }
    for(int i = 0;i<n;i++)
        for(int j = i;j<n;j++)
            cout << i+1 << ' ' << j+1 << ' ' << a[i][j] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //era(N);
    int q = 1;// cin >> q;
    while(q--)
        solve();
}

_ Gọi dp[i][j]: bằng 1 nếu xâu con từ i đến j của S là xâu đối xứng, ngược lại thì bằng 0.
_ Khởi tạo: dp[i][i] = 1 với 1 ≤ i ≤ n.
_ Công thức truy hồi:
+	dp[i][j] = 0 nếu s[i] != s[j]
+	dp[i][j] = dp[i+1][j-1] nếu s[i] = s[j]

