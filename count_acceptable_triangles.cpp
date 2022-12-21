//code của manhtuan22007
#include <bits/stdc++.h>

using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int , int> m;
    for(auto& x : a){
        cin >> x;
        ++m[x];
    }
    set<long long> s(a.begin() , a.end());
    vector<long long> b(s.begin() , s.end());

    long long res = 0;
    // tam giac can
    for(int i = 0 ; i < (int)b.size(); i++){
        if(b[i] == 1) continue;
        if(m[b[i]] >= 2){
            long long cur = 2 * b[i];
            for(int j = 0 ; j < (int)b.size() ; j++){
                if(i != j && b[j] < cur){
                    ++res;
                }
            }
        }
    }
    // tam giac co 3 canh != nhau
    for(int i = 0 ; i < (int)b.size() - 2;i ++){
        for(int j = i + 1 ; j < (int)b.size() - 1 ; j++){
            long long cur = b[i] + b[j];
            int u = lower_bound(b.begin() + j + 1 , b.end() , cur) - b.begin() - 1;
            if(j < u){
                res += u - j;
            }
        }
    }
    // tam giac deu
    for(auto& x : b){
        if(m[x] >= 3){
            ++res;
        }
    }
    cout << res;
}
