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
    LeetCode 35. Search Insert Position

    Đề bài:
    Cho một mảng số nguyên nums đã được sắp xếp tăng dần gồm các phần tử khác nhau và một giá trị target

    Yêu cầu:
    → Nếu tìm thấy target trong mảng, trả về chỉ số (index) của nó
    → Nếu không tìm thấy, trả về chỉ số (index) mà tại đó target sẽ được chèn vào để mảng vẫn giữ nguyên thứ tự sắp xếp
    → Ràng buộc hiệu năng: Thuật toán phải đạt độ phức tạp thời gian O(log n)

    Ví dụ:
        Input: nums = [1, 3, 5, 6], target = 5
        → Số 5 xuất hiện tại index 2
        → Output: 2

        Input: nums = [1, 3, 5, 6], target = 2
        → Số 2 không có trong mảng. Nếu chèn vào để giữ thứ tự [1, 2, 3, 5, 6], nó sẽ nằm ở index 1
        → Output: 1

        Input: nums = [1, 3, 5, 6], target = 7
        → Số 7 lớn hơn tất cả, sẽ được chèn vào cuối mảng tại index 4
        → Output: 4
*/

int searchInsert(vector<int>& nums, int target){
    int l = 0, r = nums.size();

    while(l < r){
        int m = (l + r) / 2;
        if(nums[m] <= target){
            l = m + 1;
        }
        else{
            r = m;
        }
    }

    if(l >= 1 && nums[l - 1] == target) return l - 1;

    return l;
}

int main(){
    FAST_IO;

    int n, target; cin >> n >> target;
    vector<int> nums(n);

    FORI(i, n) cin >> nums[i];

    int ans = searchInsert(nums, target);
    cout << ans;
    return 0;
}