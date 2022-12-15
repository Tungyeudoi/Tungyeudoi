#include <bits/stdc++.h>
#define int long long

using namespace std;

stack<int> st;
vector<pair<int, int>> matches;

bool check(string s, int n)
{

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            if (st.empty()) return false;
            matches.push_back({st.top(), i});
            st.pop();
        }
    }
    if (!st.empty()) return false;
    return true;
}

void solve()
{
    int n; string s;
    cin >> n >> s;
    cout << (check(s , n) ? "YES" : "NO");
}

#define taskname "daungoacdung"
int32_t main()
{
    if (fopen(taskname".inp", "r"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   solve();

}
