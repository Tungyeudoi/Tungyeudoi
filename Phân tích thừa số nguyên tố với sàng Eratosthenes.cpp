Cách cài đặt:

Đầu tiên hãy xem xét thuật toán phân tích ra thừa số nguyên tố trong O(N−−√)
.

vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}
Tại mỗi bước ta phải tìm số nguyên tố nhỏ nhất mà N
 chia hết cho số đó. Do đó, ta phải biến đổi sàng Eratosthenes để tìm được số mình mong muốn trong O(1)
.

int minPrime[n + 1];
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) { //if i is prime
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
Bây giờ ta có thể phân tích một số ra thừa số nguyên tố trong O(logN)
.

vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}
Điều kiện sử dụng phương pháp này là ta phải tạo được mảng có độ dài N
 phần tử.

Phương pháp này rất hữu ích khi ta phải phân tich nhiều số nhỏ ra thừa số nguyên tố. Ta không cần thiết phải sử dụng phương pháp này trong mọi bài toán liên quan đến phân tích một số ra thừa số nguyên tố. Ngoài ra, ta không thể sử dụng phương pháp này nếu N
 bằng 109
 hay 1012
. Khi đó, ta chỉ có thể sử dụng thuật toán O(N−−√)
.

Tính chất thú vị: Nếu N=pq11.pq22…pqkk
 với p1,p2,…,pk
 là các số nguyên tố thì N
 có (q1+1).(q2+1)…(qk+1)
 ước phân biệt.
