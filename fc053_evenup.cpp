#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a;
    cin >> n;
    vector<int> st;
    while (n--) {
        cin >> a;
        if (!st.empty() && (st.back() + a) % 2 == 0)
            st.pop_back();
        else
            st.push_back(a);
    }

    cout << st.size();

    return 0;
}
