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
    LeetCode 1458. Max Dot Product of Two Subsequences

    Đề bài:
    Cho hai mảng số nguyên nums1 và nums2

    Yêu cầu:
    → Tìm hai dãy con (subsequences) không rỗng, có cùng độ dài k, lần lượt từ nums1 và nums2
    → Sao cho tích vô hướng của hai dãy con này đạt giá trị lớn nhất
    → Trả về giá trị tích vô hướng cực đại đó

    Ví dụ:
        Input: nums1 = [2, 1, -2, 5], nums2 = [3, 0, -6]
        → Chọn dãy con [2, -2] từ nums1 và [3, -6] từ nums2
        → Tích vô hướng: (2 * 3) + (-2 * -6) = 6 + 12 = 18
        → Output: 18
*/

int maxDotProduct(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int prod = nums1[i] * nums2[j];

            dp[i][j] = prod;

            if(i > 0 && j > 0){
                dp[i][j] = max(dp[i][j], prod + dp[i - 1][j - 1]);
            }
                
            if(i > 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }

            if(j > 0){
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }     
        }
    }

    return dp[m - 1][n - 1];
}


int main(){
    FAST_IO;

    int m, n; cin >> m >> n;
    vector<int> nums1(m), nums2(n);

    FORI(i, m) cin >> nums1[i];
    FORI(i, n) cin >> nums2[i];

    int ans = maxDotProduct(nums1, nums2);
    cout << ans;
    return 0;
}