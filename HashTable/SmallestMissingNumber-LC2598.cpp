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
    LeetCode 2598. Smallest Missing Non-negative Integer After Operations

    Đề bài:
    Cho một mảng số nguyên nums và một số nguyên value
    Trong một thao tác, bạn có thể cộng hoặc trừ `value` vào bất kỳ phần tử nào của `nums` bao nhiêu lần tùy ý

    Định nghĩa MEX (Minimum Excluded):
    → Là số nguyên không âm nhỏ nhất không xuất hiện trong mảng
    → Ví dụ: MEX([0, 1, 3]) = 2; MEX([1, 2, 0]) = 3; MEX([-1, 2]) = 0

    Yêu cầu:
    → Sau khi thực hiện các thao tác trên, hãy tìm giá trị MEX lớn nhất có thể đạt được

    Ví dụ:
        Input: nums = [1, -10, 7, 13, 6, 8], value = 5
        → Output: 4

    Công thức tính modulo cho số âm:
        n = ((a % d) + d) % d
*/

int findSmallestInteger(vector<int>& nums, int value){
    vector<int> cnt(value, 0);

    for(int num : nums){
        int r = ((num % value) + value) % value;
        cnt[r]++;
    }

    int mex = 0;
    while(cnt[mex % value] > 0){
        cnt[mex % value]--;
        mex++;
    }
    return mex;
}


int main(){
    FAST_IO;

    int n, value; cin >> n >> value;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = findSmallestInteger(nums, value);
    cout << ans;
    return 0;
}