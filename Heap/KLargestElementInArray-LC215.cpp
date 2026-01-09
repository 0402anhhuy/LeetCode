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
    LeetCode 215. Kth Largest Element in an Array

    Đề bài:
    Cho một mảng số nguyên nums và một số nguyên k

    Yêu cầu:
    → Tìm và trả về phần tử lớn thứ k trong mảng
    → Lưu ý: Đây là phần tử lớn thứ k theo thứ tự đã sắp xếp, không phải là phần tử độc nhất (distinct) thứ k
    
    Thử thách:
    → Bạn có thể giải bài toán này mà không cần sắp xếp toàn bộ mảng (O(n log n)) không?

    Ví dụ:
        Input: nums = [3, 2, 1, 5, 6, 4], k = 2
        → Các phần tử theo thứ tự giảm dần: [6, 5, 4, 3, 2, 1]
        → Phần tử lớn thứ 2 là 5
        → Output: 5
*/

int findKthLargest(vector<int>& nums, int k){
    priority_queue<int> numbers;
    for(int num : nums){
        numbers.push(num);
    }

    int cnt = 0;
    while(cnt < k - 1){
        numbers.pop();
        cnt++;
    }

    return numbers.top();
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = findKthLargest(nums, k);
    cout << ans;
    return 0;
}