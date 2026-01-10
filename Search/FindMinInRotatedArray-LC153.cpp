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
    LeetCode 153. Find Minimum in Rotated Sorted Array

    Đề bài:
    Giả sử một mảng tăng dần độ dài n bị xoay (rotate) từ 1 đến n lần
    → Ví dụ: [0,1,2,4,5,6,7] nếu xoay 4 lần sẽ thành [4,5,6,7,0,1,2]
    → Việc xoay 1 lần đơn giản là chuyển phần tử cuối cùng lên đầu mảng
    Cho mảng nums gồm các phần tử duy nhất đã bị xoay

    Yêu cầu:
    → Tìm và trả về phần tử nhỏ nhất của mảng này
    
    Ràng buộc hiệu suất:
    → Thuật toán phải chạy trong thời gian O(log n)

    Ví dụ:
        Input: nums = [3, 4, 5, 1, 2]
        → Mảng gốc là [1, 2, 3, 4, 5] đã bị xoay 3 lần
        → Phần tử nhỏ nhất là 1
        → Output: 1

        Input: nums = [4, 5, 6, 7, 0, 1, 2]
        → Phần tử nhỏ nhất là 0
        → Output: 0
*/

int findMin(vector<int>& nums){
    int l = 0, r = nums.size() - 1;

    while(l < r){
        int m = l + (r - l) / 2;
        if(nums[m] > nums[r]){
            l = m + 1;
        }
        else{
            r = m;
        }
    }

    return nums[l];
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = findMin(nums);
    cout << ans;
    return 0;
}