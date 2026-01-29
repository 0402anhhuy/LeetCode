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
    LeetCode 69. Sqrt(x)

    Đề bài:
    Cho một số nguyên không âm x. Hãy tính căn bậc hai của x

    Yêu cầu:
    → Kết quả trả về phải được làm tròn xuống số nguyên gần nhất (phần nguyên)
    → Số nguyên trả về phải là số không âm
    → Ràng buộc: Không được sử dụng bất kỳ hàm số mũ hoặc toán tử có sẵn nào

    Ví dụ:
        Input: x = 4
        → Căn bậc hai của 4 là 2
        → Output: 2

        Input: x = 8
        → Căn bậc hai của 8 là 2.82842..., làm tròn xuống lấy phần nguyên là 2
        → Output: 2
*/

int mySqrt(int x){
    if(x == 0 || x == 1) return x;

    int l = 0, r = x, ans = 0;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(m <= x / m){
            ans = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return ans;
}

int main(){
    FAST_IO;

    int x; cin >> x;

    int ans = mySqrt(x);
    cout << ans;
    return 0;
}