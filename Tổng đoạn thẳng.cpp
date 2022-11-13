/*Bài 2: Tổng đoạn thẳng
Cho n (n ≤ 10000) đoạn thẳng trên trục số với các điểm đầu xi và độ dài di (|xi
|, di là
những số nguyên không vượt quá 109
). Tính tổng độ dài trên trục số bị phủ bởi n đoạn
trên.
Ví dụ: Có 3 đoạn x1=-5, d1=10; x2=0, d2=6; x3=-100, d3=10 thì tổng độ dài trên trục
số bị phủ bởi 3 đoạn trên là 21.
Dữ liệu vào từ tệp văn bản TONGDD.INP có cấu trúc như sau:
 Dòng 1: chứa số nguyên dương n (1≤n ≤ 10000).
 Dòng thứ i trong n dòng tiếp theo ghi tọa độ điểm đầu và độ dài của đoạn thẳng
thứ i (các số cách nhau một dấu cách)
Kết quả ghi ra tệp văn bản TONGDD.OUT: ghi tổng độ dài trên trục số bị phủ bởi n
đoạn thẳng đã cho.
Ví dụ:
TONGDD.INP TONGDD.OUT
3           21
-5 10
0 6
-100 10*/


#include <bits/stdc++.h>
#define int long long
using namespace std;
int i,p,b,n,t=0,sum;
pair<int,int> a[10005];
int32_t main(){
cin>>n;
for(i=1;i<=n;i++){
    cin >> a[i].first >> a[i].second;
}
sort(a+1,a+n+1);
p=a[1].first;
b=a[1].first+a[1].second;
for(i=2;i<=n;i++){
    if(a[i].first<=b){ b=max(b,a[i].first+a[i].second);
    }
else {
    t = t + (b - p);
    p = a[i].first; b = p + a[i].second;
}
}
sum=t+(b-p);
cout << sum ;
return 0;

}
