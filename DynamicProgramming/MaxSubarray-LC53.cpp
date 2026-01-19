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
    LeetCode 53. Maximum Subarray

    Đề bài:
    Cho một mảng số nguyên nums. Hãy tìm một mảng con (subarray) liên tục sao cho tổng của các phần tử trong mảng con đó là lớn nhất

    Yêu cầu:
    → Trả về giá trị tổng lớn nhất tìm được
    → Mảng con phải là một phần liên tiếp của mảng ban đầu

    Ví dụ:
        Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        → Mảng con [4, -1, 2, 1] có tổng là 6, đây là tổng lớn nhất có thể đạt được
        → Output: 6

        Input: nums = [5, 4, -1, 7, 8]
        → Mảng con [5, 4, -1, 7, 8] có tổng là 23
        → Output: 23
*/

int maxSubArray(vector<int>& nums){
    int ans = nums[0];
    int dp = nums[0];

    for(int i = 1; i < nums.size(); i++){
        dp = max(nums[i], dp + nums[i]);
        ans = max(ans, dp);
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int ans = maxSubArray(nums);
    cout << ans;
    return 0;
}