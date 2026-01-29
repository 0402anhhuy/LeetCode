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
    LeetCode 367. Valid Perfect Square

    Đề bài:
    Cho một số nguyên dương num. Hãy kiểm tra xem số đó có phải là một số chính phương (perfect square) hay không

    Định nghĩa:
    → Một số chính phương là một số nguyên có giá trị bằng bình phương của một số nguyên khác

    Yêu cầu:
    → Trả về true nếu num là số chính phương, ngược lại trả về false
    → Ràng buộc: Không được sử dụng bất kỳ hàm thư viện có sẵn nào như sqrt

    Ví dụ:
        Input: num = 16
        → 4 * 4 = 16
        → Output: true

        Input: num = 14
        → Không có số nguyên nào bình phương bằng 14
        → Output: false
*/

bool isPerfectSquare(int num){
    if(num == 0 || num == 1) return num;

    int l = 0, r = num, ans = 0;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(m <= num / m){
            ans = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }

    return ans * ans == num;
}

int main(){
    FAST_IO;

    int num; cin >> num;
    cout << boolalpha << isPerfectSquare(num);
    return 0;
}