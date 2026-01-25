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
    LeetCode 1984. Minimum Difference Between Highest and Lowest of K Scores

    Đề bài:
    Cho một mảng số nguyên nums (chỉ số bắt đầu từ 0), trong đó nums[i] là điểm số của học sinh thứ i. Bạn cũng được cho một số nguyên k

    Yêu cầu:
    → Chọn ra điểm số của k học sinh bất kỳ từ mảng sao cho hiệu số giữa điểm cao nhất và điểm thấp nhất trong nhóm k học sinh đó là nhỏ nhất
    → Trả về giá trị hiệu số nhỏ nhất đó

    Ví dụ:
        Input: nums = [9, 4, 1, 7], k = 2
        → Nếu chọn [9, 4]: Hiệu là 9 - 4 = 5
        → Nếu chọn [4, 1]: Hiệu là 4 - 1 = 3
        → Nếu chọn [7, 9]: Hiệu là 9 - 7 = 2
        → Nếu chọn [7, 4]: Hiệu là 7 - 4 = 3
        → Hiệu nhỏ nhất tìm được là 2
        → Output: 2
*/

int minimumDifference(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());

    int ans = nums[k - 1] - nums[0];
    for(int i = 1; i <= nums.size() - k; i++){
        ans = min(ans, nums[k + i - 1] - nums[i]);
    }

    return ans;
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<int> nums(n);

    FORI(i, n) cin >> nums[i];

    int ans = minimumDifference(nums, k);
    cout << ans;
    return 0;
}