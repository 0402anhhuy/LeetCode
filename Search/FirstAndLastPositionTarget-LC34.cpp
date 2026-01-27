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
    LeetCode 34. Find First and Last Position of Element in Sorted Array

    Đề bài:
    Cho một mảng số nguyên nums đã được sắp xếp theo thứ tự không giảm (tăng dần) và một giá trị target

    Yêu cầu:
    → Tìm vị trí bắt đầu và vị trí kết thúc của giá trị target trong mảng
    → Nếu không tìm thấy target trong mảng, trả về [-1, -1]
    
    Ràng buộc hiệu suất:
    → Thuật toán phải có độ phức tạp thời gian là O(log n)

    Ví dụ:
        Input: nums = [5, 7, 7, 8, 8, 10], target = 8
        → Số 8 xuất hiện lần đầu tại index 3 và lần cuối tại index 4
        → Output: [3, 4]

        Input: nums = [5, 7, 7, 8, 8, 10], target = 6
        → Số 6 không tồn tại trong mảng
        → Output: [-1, -1]
*/

int lowerBound(vector<int> nums, int target){
    int left = 0, right = nums.size() - 1;

    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }

    return left;
}

int upperBound(vector<int> nums, int target){
    int left = 0, right = nums.size();

    while(left < right){
        int mid = (left + right) / 2;
        if(nums[mid] <= target){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}

vector<int> searchRange(vector<int>& nums, int target){
    int n = nums.size();
    if(n == 0) return {-1, -1};

    int first = lowerBound(nums, target);
    int last = upperBound(nums, target);

    if(first > n - 1 || nums[first] != target || nums[last - 1] != target) return {-1, -1};
    return {first, last - 1};
}

int main(){
    FAST_IO;

    int n, target; cin >> n >> target;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<int> ans = searchRange(nums, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}