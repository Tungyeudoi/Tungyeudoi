#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5+11;
const int inf = 1e18 + 11;

int n , m;
int a[N] , b[N] , aa[N];
bool mark[N];
map <int, int> check , pos , ans;
void solve()
{
    cin >> n >> m;
    for(int i = 1;i<=n;i++) {cin >> a[i]; aa[i] = a[i];}
    for(int i = 1;i<=m;i++){
        cin >> b[i];
        check[b[i]]=1;
        pos[b[i]] = i;
    }

    vector<int> car , trap;
    for(int i = 1;i<=n;i++)
        if(check[a[i]] == 1){
            ans[a[i]] = pos[a[i]];
            check[a[i]] = inf;
            a[i] = inf;
        }

    for(auto x : check)
        if(x.second == 1) trap.push_back(x.first);

    for(int i = 1;i<=n;i++)
        if(a[i] != inf) car.push_back(a[i]);

    reverse(car.begin(),car.end());
    for(auto x : car){
        int posi = upper_bound(trap.begin(),trap.end(),x) - trap.begin();
        if(posi >= trap.size()) {ans[x] = -1;continue;}
        if( trap[posi]>x && check[trap[posi]]==1){
            ans[x] = pos[trap[posi]];
            check[trap[posi]] = inf;
            trap.erase(trap.begin() + posi);
        }
    }

    for(int i = 1;i<=n;i++) cout << ((ans[aa[i]] != 0) ?  ans[aa[i]] : -1) << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int q = 1;
    //cin >> q;
    while(q--) solve();
}
/*
Bài 2: Quá tải
Trên đường cao tốc dẫn đến bến cảng có rất nhiều xe lưu thông. Các xe khi rời cảng
được kiểm soát chặt không để xẩy ra hiện tượng chở quá tải, nhưng các xe chở hàng
tới có thể vi phạm các quy định về tải trọng. Để phát hiện và bắt giữ các xe vi phạm
người ta bố trí trên đường m thiết bị cân tự động, thiết bị thứ i đặt ở ki lô mét bi
(0 ≤ bi ≤ bi+1, i = 1, 2, . . ., m-1). Nếu xe có tải trọng lớn hơn mức được phép đi
qua cân, các cảm biến sẽ được kích hoạt, các má phanh bật lên ôm sát bánh buộc xe
phải dừng lại. Mỗi cân chỉ được kích hoạt tự động một lần, muốn tháo cân trả về
trạng thái ban đầu phải có sự can thiệp trực tiếp của cán bộ vận hành.
Có n xe quá tải lưu thông trên đường, xe thứ j vào đường cao tốc ở km aj (0 ≤
aj ≤ aj+1,
j = 1, 2, . . ., n-1). Nếu một xe đang ở vị trí km x và vẫn đi được thì sau một đơn
vị thời gian xe sẽ ở vị trí x+1.
Yêu cầu: Với mỗi xe hãy xác định nó sẽ bị cân tự động nào phát hiện. Nếu xe không
bị phát hiện thì đưa ra số -1.
Dữ liệu: Vào từ file văn bản OVERLOAD.INP:
 Dòng đầu tiên chứa 2 số nguyên n và m (1 ≤ n, m ≤ 105
),
 Dòng thứ 2 chứa n số nguyên a1, a2, . . ., an (0 ≤ aj ≤ aj+1 ≤ 109
, j = 1,
2, . . ., n-1),
 Dòng thứ 3 chứa m số nguyên b1, b2, . . ., bm (0 ≤ bi ≤ bi+1 ≤ 109
, i = 1,
2, . . ., m-1).
Kết quả: Đưa ra file văn bản OVERLOAD.OUT n số nguyên, mỗi số trên một
dòng, số thứ j xác định số thứ tự của cân phát hiện xe j, j=1, 2, . . ., n.
Ví dụ:
OVERLOAD.INP OVERLOAD.OUT
8 6
0 2 3 4 5 6 8 13
1 3 5 6 9 12
1
-1
2
6
3
4
5
-1*/
