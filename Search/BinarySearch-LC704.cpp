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
    LeetCode 704. Binary Search

    Đề bài:
    Cho một mảng số nguyên nums đã được sắp xếp theo thứ tự tăng dần và một số nguyên target

    Yêu cầu:
    → Tìm kiếm sự hiện diện của target trong mảng nums
    → Nếu tìm thấy, trả về chỉ số (index) của phần tử đó
    → Nếu không tìm thấy, trả về -1
    → Ràng buộc hiệu năng: Thuật toán phải đạt độ phức tạp thời gian O(log n)

    Ví dụ:
        Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
        → Số 9 nằm ở vị trí index 4
        → Output: 4

        Input: nums = [-1, 0, 3, 5, 9, 12], target = 2
        → Số 2 không tồn tại trong mảng
        → Output: -1
*/

int search(vector<int>& nums, int target){
    int l = 0, r = nums.size() - 1;

    while(l < r){
        int m = (l + r) / 2;
        if(nums[m] < target){
            l = m + 1;
        }
        else{
            r = m;
        }
    }

    return (nums[l] == target) ? l : -1;
}

int main(){
    FAST_IO;

    int n, target; cin >> n >> target;
    vector<int> nums(n);

    FORI(i, n) cin >> nums[i];

    int ans = search(nums, target);
    cout << ans;
    return 0;
}