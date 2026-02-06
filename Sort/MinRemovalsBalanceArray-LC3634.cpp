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
    LeetCode 3634. Minimum Removals to Balance Array

    Đề bài:
    Cho một mảng số nguyên nums và một số nguyên k
    Một mảng được coi là cân bằng (balanced) nếu giá trị của phần tử lớn nhất (max) không vượt quá k lần phần tử nhỏ nhất (min)
    
    Điều kiện: max <= k * min

    Yêu cầu:
    → Bạn có thể xóa bất kỳ số lượng phần tử nào từ mảng nums (nhưng không được xóa hết mảng)
    → Tìm số lượng phần tử ít nhất cần xóa để phần tử còn lại tạo thành một mảng cân bằng

    Ví dụ:
        Input: nums = [2, 1, 5], k = 2
        - Nếu giữ nguyên [2, 1, 5]: max=5, min=1. Mà 5 > 2*1 (Không cân bằng)
        - Nếu xóa số 5: Còn [2, 1]. max=2, min=1. Mà 2 <= 2*1 (Cân bằng). Số lượng xóa: 1
        - Nếu xóa số 1: Còn [2, 5]. max=5, min=2. Mà 5 > 2*2 (Không cân bằng)
        - Nếu xóa 1 và 2: Còn [5]. (Cân bằng). Số lượng xóa: 2
        → Kết quả ít nhất là xóa 1 phần tử
        → Output: 1
*/

int minRemoval(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int ans = n, right = 0;
    for(int left = 0; left < n; left++){
        while(right < n && nums[right] <= static_cast<long long>(nums[left]) * k){
            right++;
        }

        ans = min(ans, n - (right - left));
    }

    return ans;
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = minRemoval(nums, k);
    cout << ans;
    return 0;
}