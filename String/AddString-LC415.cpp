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
    LeetCode 415. Add Strings

    Đề bài:
    Cho hai số nguyên không âm num1 và num2 được biểu diễn dưới dạng chuỗi (string)

    Yêu cầu:
    → Tính tổng của num1 và num2 và trả về kết quả dưới dạng một chuỗi
    
    Ràng buộc:
    1. Không được sử dụng các thư viện có sẵn để xử lý số nguyên lớn (như BigInteger)
    2. Không được chuyển đổi trực tiếp toàn bộ chuỗi đầu vào thành số nguyên (vì số có thể cực kỳ lớn, vượt quá giới hạn của kiểu dữ liệu long long).

    Ví dụ:
        Input: num1 = "11", num2 = "123"
        → 11 + 123 = 134
        → Output: "134"

        Input: num1 = "456", num2 = "77"
        → 456 + 77 = 533
        → Output: "533"
*/

string addStrings(string num1, string num2){
    string res = "";
    while(num1.length() < num2.length()){
        num1 = '0' + num1;
    }

    while(num2.length() < num1.length()){
        num2 = '0' + num2;
    }

    int carry = 0;
    for(int i = num1.length() - 1; i >= 0; i--){
        int x = (num1[i] - '0') + (num2[i] - '0') + carry;
        res += (x % 10) + '0';
        carry = x / 10;
    }
    if(carry != 0) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    FAST_IO;

    string num1, num2; cin >> num1 >> num2;
    string res = addStrings(num1, num2);
    cout << res;

    return 0;
}