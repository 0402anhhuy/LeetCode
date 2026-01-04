#include<bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr)

using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define F first
#define S second

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORI(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (n)-1; i >= 0; --i)

const int INF = 1e9 + 7;
const ll  LINF = 4e18;
const ld  EPS = 1e-9;
const int MOD = 1e9 + 7;

/*
    LeetCode 8. String to Integer (atoi)

    Đề bài:  
    Thiết lập hàm myAtoi(string s) để chuyển đổi một chuỗi ký tự thành một số nguyên có dấu 32-bit

    Yêu cầu thuật toán:  
    1. Khoảng trắng: Bỏ qua tất cả các dấu cách trống (" ") ở đầu chuỗi
    2. Dấu: Kiểm tra ký tự tiếp theo là '-' hoặc '+' để xác định số âm hay dương (nếu không có thì mặc định là dương)
    3. Chuyển đổi: Đọc các ký tự số tiếp theo, bỏ qua các số 0 ở đầu cho đến khi gặp ký tự không phải số hoặc hết chuỗi. Nếu không có số nào, kết quả là 0.
    4. Làm tròn (Rounding): Nếu giá trị vượt quá phạm vi số nguyên có dấu 32-bit [-2^{31}, 2^{31} - 1]:
       → Nếu nhỏ hơn -2^{31}, trả về -2^{31}
       → Nếu lớn hơn 2^{31} - 1, trả về 2^{31} - 1
    → Trả về số nguyên kết quả cuối cùng

    Ví dụ:  
        Input: s = "   -42"  
        → Bỏ qua khoảng trắng: "-42"
        → Xác định dấu: Số âm (-)
        → Đọc số: 42
        → Output: -42

        Input: s = "1337c0d3"
        → Đọc số đến khi gặp 'c': 1337
        → Output: 1337
*/

string cleanSpace(string s){
    int n = s.size();
    if(n == 0) return s;

    int left = 0;
    while(left < n && s[left] == ' '){
        left++;
    }

    if(left == n) return "";

    int right = n - 1;
    while(right >= 0 && s[right] == ' '){
        right--;
    }

    return s.substr(left, right - left + 1);
}


int myAtoi(string s){
    s = cleanSpace(s);
    if (s.empty()) return 0;

    int sign = 1;
    int i = 0;
    long long num = 0;

    if(s[i] == '+' || s[i] == '-'){
        if(s[i] == '-') sign = -1;
        i++;
    }

    while(i < s.size() && isdigit(s[i])){
        num = num * 10 + (s[i] - '0');

        if(sign == 1 && num > INT_MAX) return INT_MAX;
        if(sign == -1 && -num < INT_MIN) return INT_MIN;

        i++;
    }

    return (int)(num * sign);
}


int main(){
    FAST_IO;

    string s;
    getline(cin, s);

    int ans = myAtoi(s);
    cout << ans;
    return 0;
}