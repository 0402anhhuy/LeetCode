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
    LeetCode 1877. Minimize Maximum Pair Sum in Array

    Đề bài:
    Cho một mảng nums có độ dài chẵn n. Bạn cần chia tất cả các phần tử trong mảng thành n / 2 cặp sao cho mỗi phần tử nằm trong đúng một cặp

    Định nghĩa:
    1. Tổng cặp (Pair sum): Là tổng của hai phần tử trong một cặp (a + b)
    2. Tổng cặp cực đại (Maximum pair sum): Là giá trị lớn nhất trong số các tổng của các cặp đã chia

    Yêu cầu:
    → Hãy tìm cách ghép cặp sao cho Tổng cặp cực đại đạt giá trị nhỏ nhất có thể
    → Trả về giá trị nhỏ nhất đó

    Ví dụ:
        Input: nums = [3, 5, 2, 3]
        → Cách 1: (3,3) và (5,2) -> Tổng là 6 và 7. Max = 7
        → Cách 2: (3,5) và (3,2) -> Tổng là 8 và 5. Max = 8
        → Cách 3: (3,2) và (3,5) -> Giống cách 2
        → Cách tối ưu: Ghép số nhỏ nhất với số lớn nhất: (2,5) và (3,3). Tổng là 7 và 6. Max = 7
        → Output: 7
*/

int minPairSum(vector<int>& nums){
    sort(nums.begin(), nums.end());

    int l = 0, r = nums.size() - 1;

    int ans = INT_MIN;
    while(l < r){
        ans = max(ans, (nums[l] + nums[r]));
        l++;
        r--;
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);

    FORI(i, n) cin >> nums[i];

    int ans = minPairSum(nums);
    cout << ans;
    return 0;
}