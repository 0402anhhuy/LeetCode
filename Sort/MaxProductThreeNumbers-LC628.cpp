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
    LeetCode 628. Maximum Product of Three Numbers

    Đề bài:
    Cho một mảng số nguyên nums

    Yêu cầu:
    → Tìm ba số trong mảng sao cho tích của chúng đạt giá trị lớn nhất
    → Trả về giá trị tích cực đại đó

    Ví dụ:
        Input: nums = [1, 2, 3]
        → Tích: 1 * 2 * 3 = 6
        → Output: 6

        Input: nums = [1, 2, 3, 4]
        → Tích: 2 * 3 * 4 = 24
        → Output: 24

        Input: nums = [-10, -10, 1, 3, 2]
        → Cách 1: Ba số dương lớn nhất: 1 * 2 * 3 = 6
        → Cách 2: Hai số âm nhỏ nhất và số dương lớn nhất: (-10) * (-10) * 3 = 300
        → Kết quả: 300
*/

int maximumProduct(vector<int>& nums){
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int first = nums[0] * nums[1] * nums[2];
    int second = nums[n - 3] * nums[n - 2] * nums[n - 1];
    int third = nums[0] * nums[1] * nums[n - 1];

    return max({first, second, third});
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = maximumProduct(nums);
    cout << ans;
    return 0;
}