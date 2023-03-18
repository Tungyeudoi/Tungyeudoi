#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define int long long

using namespace std;

const int N = 1e6 + 111;
const int INF = 1e18 + 11;
const int mod = 1e9 + 7;
vector<int> minPrime(N + 1 , 0);
vector<bool> sieve(N + 1 , 1);

void era(int n){
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i = 2;i*i<=n;i++)
        if(sieve[i])
        for(int j = i*i;j<=n;j+=i)
            sieve[j] = 0;
}

void minPr(int n){
    minPrime[1] = minPrime[0] = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
}
void solve()
{
    int n , ans = 1;
    cin >> n;
    set <int> s;
    map <int,int> m;
    for(int i = 1;i<=n;i++){
        int x; cin >> x;
        // if x is prime

        if(sieve[x]){
            s.insert(x);
            m[x]++;
            continue;
        }
        //x not prime
        vector<int> tmp;
        while (x != 1) {
            tmp.push_back(minPrime[x]);
            x /= minPrime[x];
        }
        for(auto xx: tmp){
            s.insert(xx);
            m[xx]++;
        }

    }

    for(auto& x : s){
        ans = ((ans % mod) * (m[x] + 1)% mod) % mod;
    }
    cout << ans;

}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    minPr(N);
    era(N);
    int q = 1; //cin >> q;
    while(q--)
        solve();
}
ĐẾM ƯỚC
Trạng nguyên Lương Thế Vinh sinh tại làng Cao Hương, huyện Thiên Bản,
Trấn Sơn Nam (nay là thôn Cao Phương, xã Liên Bảo, huyện Vụ Bản, tỉnh Nam
Định). Từ nhỏ Lương Thế Vinh đã nổi tiếng thông minh, nhanh trí và khả năng sáng
tạo trong các trò chơi như đá bóng, thả diều, câu cá, bẫy chim. Nhờ khả năng về toán
học và đo lường mà sau này ông được nhân dân gọi là Trạng Lường khi đỗ trạng
nguyên.
Sự sáng tạo khoa học của Lương Thế Vinh được truyền khẩu qua câu chuyện
ông tiếp đón sứ nhà Minh là Chu Hy. Nghe nói Lương Thế Vinh, không những nổi
tiếng về văn chương, âm nhạc mà còn tinh thông toán học, nên sứ giả thách đố ông
cân một con voi. Lương Thế Vinh đưa voi lên một chiếc thuyền rồi đánh dấu mép
nước bên thuyền, sau đó dắt voi lên. Tiếp theo, ông ra lệnh đổ đá hộc xuống thuyền,
cho đến lúc thuyền chìm xuống đến đúng dấu cũ. Việc còn lại là đưa từng viên đá
lên cân và cộng kết quả. Chu Hy thán phục ông nhưng tiếp tục đố ông đo bề dày của
một tờ giấy xé ra từ một quyển sách. Khi nghe ông nói chỉ cần đo bề dày cả cuốn
sách rồi chia đều cho số tờ là ra ngay kết quả, Chu Hy ngửa mặt lên trời than: "Nước
Nam quả có lắm người tài !".
Tiếp nối những thành tựu của Lương Thế Vinh, phát huy truyền thống giỏi
tính toán, em hãy giải quyết bài toán sau: Cho n số nguyên dương a1, a2, … ,an. Gọi
ܵ = ܽଵ × ܽଶ ×…× ܽ௡.
Yêu cầu: Đếm số lượng ước nguyên dương của S.
Dữ liệu
- Dòng 1: Gồm 1 số nguyên n (1 ≤ n ≤ 106
).
- Dòng 2: Gồm n số nguyên a1,a2, … , an (2 ≤ ai ≤ 106
).
Kết quả
Một số duy nhất là số lượng ước nguyên dương tìm được. Vì kết quả có thể rất lớn,
đưa ra phần dư cho 109+7.
Ví dụ:
input output
3
2 3 2
6
Giới hạn:
- Subtask 1 (25% số điểm): s ≤ 1012
- Subtask 2 (25% số điểm): ai nguyên tố (với 1 ≤ i ≤ n)
- Subtask 3 (25% số điểm): n ≤ 1000
- Subtask 4 (25% số điểm): Không có điều kiện gì thêm.
