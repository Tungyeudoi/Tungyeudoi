#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    //Sieve of Eratosthenes : Sàng nguyên tố
    vector<bool> sieve(n,1);
    sieve[0] = 0;
    sieve[1] = 1;
    for(int i = 2;i*i<=n;i++)
        if(sieve[i])
        for(int j = i*i;j<=n;j+=i)
            sieve[j] = 0;

}
