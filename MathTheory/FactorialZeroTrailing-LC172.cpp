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
    LeetCode 172. Factorial Trailing Zeroes

    Đề bài:
    Cho một số nguyên n. Hãy tính số lượng chữ số 0 tận cùng của giai thừa n!
    → Định nghĩa: n! = n times (n - 1) times (n - 2) times dots times 1

    Yêu cầu:
    → Trả về số lượng chữ số 0 ở cuối kết quả của phép tính giai thừa.
    → Thử thách: Thuật toán của bạn nên chạy trong thời gian logarit O(log n)

    Ví dụ:
        Input: n = 3
        → 3! = 6. Không có số 0 tận cùng
        → Output: 0

        Input: n = 5
        → 5! = 120. Có một số 0 tận cùng
        → Output: 1

        Input: n = 0
        → 0! = 1. Không có số 0 tận cùng
        → Output: 0
*/

int trailingZeroes(int n){
    int ans = 0;
    for(int i = 5; i <= n; i *= 5){
        ans += n / i;
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    int ans = trailingZeroes(n);
    cout << ans;
    return 0;
}