#include <bits/stdc++.h>
//#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define int long long

using namespace std;

const int N = 1e7 + 11;
const int INF = 1e18 + 11;
const int lim_inf = 1e7 + 11;   

bool f[2500][2500];
int main(){
     string s;
    cin >> s;
    int cnt = 0 , n = s.size();
    s = " " + s;
    for(int i = 1;i<=n;i++) f[i][i] = 1;
    for(int i = 1;i<=n;i++)
        for(int j = i+1;j<=n;j++)
            if(s[i] == s[j])
                f[i][j] = f[i+1][j-1];
            else
                f[i][j] = 0;
  
}
_ Gọi dp[i][j]: bằng 1 nếu xâu con từ i đến j của S là xâu đối xứng, ngược lại thì bằng 0.
_ Khởi tạo: dp[i][i] = 1 với 1 ≤ i ≤ n.
_ Công thức truy hồi:
+	dp[i][j] = 0 nếu s[i] != s[j]
+	dp[i][j] = dp[i+1][j-1] nếu s[i] = s[j]

