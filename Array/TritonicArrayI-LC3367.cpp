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
    LeetCode 3637. Trionic Array I

    Đề bài:
    Cho một mảng số nguyên nums có độ dài n
    Một mảng được gọi là trionic nếu tồn tại hai chỉ số p và q (0 < p < q < n - 1) chia mảng thành 3 phần thỏa mãn:

    1. Đoạn đầu (từ 0 đến p): Tăng nghiêm ngặt (strictly increasing)
    2. Đoạn giữa (từ p đến q): Giảm nghiêm ngặt (strictly decreasing)
    3. Đoạn cuối (từ q đến n - 1): Tăng nghiêm ngặt (strictly increasing)

    Yêu cầu:
    → Trả về true nếu mảng là trionic, ngược lại trả về false

    Ví dụ:
        Input: nums = [1, 3, 5, 4, 2, 6]
        → Đoạn [1, 3, 5] tăng (p=2).
        → Đoạn [5, 4, 2] giảm (q=4).
        → Đoạn [2, 6] tăng.
        → Thỏa mãn cấu trúc "Lên - Xuống - Lên"
        → Output: true

        Input: nums = [1, 2, 3, 4]
        → Không thể chia thành 3 phần thỏa mãn điều kiện giảm ở giữa
        → Output: false
*/

bool isTrionic(vector<int>& nums){
    int p = -1, q = -1, n = nums.size();
    for(int i = 1; i < n; i++){
        if(nums[i - 1] == nums[i]) return false;
        if(nums[i - 1] > nums[i]){
            p = i - 1;
            break;
        }
    }

    if(p == -1) return false;

    for(int i = p + 1; i < n; i++){
        if(nums[i - 1] == nums[i]) return false;
        if(nums[i - 1] < nums[i]){
            q = i - 1;
            break;
        }
    }

    if(q == -1) return false;

    for(int i = q + 1; i < n; i++){
        if(nums[i - 1] > nums[i] || nums[i - 1] == nums[i]){
            return false;
        }
    }

    return p > 0 && q > 0;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    cout << boolalpha << isTrionic(nums);
    return 0;
}