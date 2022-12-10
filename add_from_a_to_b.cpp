#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,q,a,b,c[10000007],i,ma=0;
    cin >> n >> q;
    for(i=0;i<=n;i++) c[i]=0;
    while(q--){
        cin >> a >> b ;
        c[a]+=1;
        c[b+1]-=1;
 
    }
    for (i=1;i<=n;i++){
        c[i]+=c[i-1];
        cout << c[i] << ' ';
    }
 
 
    return 0;
}
