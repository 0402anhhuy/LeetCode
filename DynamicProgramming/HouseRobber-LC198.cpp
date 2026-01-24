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
    LeetCode 198. House Robber

    Đề bài:  
    Bạn là một tên trộm chuyên nghiệp đang lập kế hoạch đi trộm các ngôi nhà dọc theo một con phố
    Mỗi ngôi nhà có một số tiền nhất định (nums[i])

    Yêu cầu:  
    → Bạn cần chọn các ngôi nhà để trộm sao cho tổng số tiền thu được là lớn nhất
    → Ràng buộc: Không được trộm hai ngôi nhà liền kề nhau trong cùng một đêm, vì hệ thống an ninh sẽ tự động báo cảnh sát
    → Trả về tổng số tiền tối đa có thể trộm được mà không làm báo động kêu

    Ví dụ:  
        Input: nums = [1, 2, 3, 1]  
        → Cách 1: Trộm nhà 1 (1) và nhà 3 (3) => Tổng = 1 + 3 = 4
        → Cách 2: Trộm nhà 2 (2) và nhà 4 (1) => Tổng = 2 + 1 = 3
        → Output: 4
*/

int rob(vector<int>& nums){
    int n = nums.size();
    if(n == 1) return nums[0];
    
    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
   
    FORI(i, n) cin >> nums[i];
    int ans = rob(nums);
    cout << ans;
    return 0;
}