/*
Đoạn gối
Cho N đoạn thẳng trên trục số với các điểm đầu ai và điểm cuối bi là những số
nguyên trong khoảng 1000..1000, ai < bi. Hãy tìm số lượng tối đa K đoạn thẳng
gối nhau liên tiếp.
Hai đoạn thẳng [a,b] và [c,d] được gọi là gối nhau nếu xếp chúng trên cùng một
trục số thì điểm đầu đoạn này trùng với điểm cuối của đoạn kia, tức là c=b hoặc
d=a.
Ví dụ: Có 5 đoạn: a1=2, b2=7; a2=1, b2=3; a3=7, b3=9; a4=3, b4=4; a5=4, b5=5 thì có
tối đa 3 đoạn gối nhau liên tiếp là [1,3], [3, 4] và [4, 5].
Dữ liệu vào từ tệp văn bản DOANGOI.INP có cấu trúc như sau:
 Dòng 1: Ghi số số nguyên dương n (1≤n ≤ 1000).
 Dòng thứ i trong n dòng tiếp theo ghi tọa độ điểm đầu và điểm cuối của đoạn
thẳng thứ i (các số cách nhau một dấu cách)
Kết quả ghi ra tệp văn bản DOANGOI.OUT: ghi số tự nhiên K (số lượng tối đa các
đoạn thẳng gối nhau liên tiếp).
DOANGOI.INP DOANGOI.OUT
5            3
2 7
1 3
7 9
3 4
4 5
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , f[2005];
pair<int,int> v[1005];
int32_t main(){
cin>>n;
for(int i=1;i<=n;i++){
    cin >> v[i].first >> v[i].second;
    f[i] = 1;
}
sort(v+1,v+n+1);
for(int i = 1 ; i <= n ;i ++){
    for(int j = 1 ; j < i ; j ++) if(v[j].second == v[i].first) f[i] = max(f[i] , f[j] + 1);
}
cout << *max_element(f + 1 , f + n + 1);
return 0;
}
