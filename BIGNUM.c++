///TungLeTrong
//contact : tungletrong173@gmail.com
//fb : https://www.facebook.com/gnuTgnorTeL/
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn = 1e12 + 11;

string Sum(string a, string b)
{
    string c;
    int n1 = a.size(), n2 = b.size(), mem = 0, Sum;
    if(n1 > n2) b.insert(0, n1 - n2, '0');
    if(n1 < n2) a.insert(0, n2 - n1, '0');
    c = a;
    for(int i = n1 - 1; i>=0; i--)
    {
        Sum = (a[i]-48) + (b[i]-48) + mem;
        mem = Sum / 10;
        Sum = Sum % 10;
        c[i] = char(Sum + 48);
    }
    if(mem > 0) c = char(mem+48) + c;
    return c;
}

string Minus(string a, string b)
{
    string c = "";
    int n1 = a.size(), n2 = b.size(), muon = 0, Hieu;
    if(n1 > n2) b.insert(0, n1-n2, '0');
    for(int i = n1 - 1; i >0; i--)
    {
        Hieu = (a[i] - 48) - (b[i] - 48) - muon;
        if(Hieu < 0)
        {
            Hieu += 10;
            muon = 1;
        }
        else muon = 0;
        c = char(Hieu + 48) + c;
    }
    while(c.size() > 1 && c[0]=='0') c.erase(0, 1);
    return c;
}

string nhan_so_lon_voi_so_nho(string a, int k)
{
    string b;
    int nho = 0, tich;
    for(int i = a.size() - 1; i>=0; --i)
    {
        tich = nho + (a[i] + 48) * k;
        nho = tich / 10;
        tich = tich % 10;
        b = b + char(tich+48);
    }
    if(nho != 0) b = char(nho+48) + b;
    while(b.size() >1 && b[0]=='0') b.erase(0,1);
    return b;
}

string nhanxau(string a, string b)
{
    string x, tg1 = "0", tg2, c;
    int j = 0;
    for(int i = b.size()-1; i>=0; --i)
    {
        tg2 = nhan_so_lon_voi_so_nho(a, b[i]-48);
        tg2.insert(tg2.size(), j,'0');
        j++;
        c = Sum(tg1,tg2);
        tg1 = c;
    }
    return c;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    cout << nhanxau(a, b);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    //cin >> q;
    while(q--)
        solve();

}
///TungLeTrong
