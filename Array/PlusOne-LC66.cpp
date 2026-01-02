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
    LeetCode 66. Plus One

    Đề bài:
    Cho một số nguyên lớn được đại diện bởi một mảng số nguyên digits
    → Mỗi phần tử digits[i] là một chữ số của số nguyên đó
    → Các chữ số được sắp xếp theo thứ tự từ quan trọng nhất đến ít quan trọng nhất (từ trái qua phải)
    → Số nguyên này không chứa bất kỳ số 0 nào ở đầu (ngoại trừ chính số 0)

    Yêu cầu:
    → Cộng thêm 1 vào số nguyên lớn đó
    → Trả về mảng các chữ số sau khi đã cộng thêm 1
    → Lưu ý: Cần xử lý trường hợp "nhớ" (carry) khi cộng, ví dụ như số 9 cộng 1 sẽ thành 10

    Ví dụ:
        Input: digits = [1, 2, 3]
        → Số nguyên là 123
        → 123 + 1 = 124
        → Output: [1, 2, 4]

        Input: digits = [9, 9]
        → Số nguyên là 99
        → 99 + 1 = 100
        → Output: [1, 0, 0]
*/

vector<int> plusOne(vector<int>& digits){
    vector<int> ans;
    int n = digits.size(), carry = 0, sum = 0;

    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1){
            sum = digits[i] + 1;
        }
        else sum = digits[i] + carry;

        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    if(carry != 0) ans.push_back(carry);
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> digits(n);
    FORI(i, n) cin >> digits[i];
    
    vector<int> ans = plusOne(digits);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}