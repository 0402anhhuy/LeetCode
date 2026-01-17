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
    LeetCode 2997. Minimum Number of Operations to Make Array XOR Equal to K

    Đề bài:
    Cho một mảng số nguyên nums và một số nguyên dương k
    Bạn có thể thực hiện thao tác sau bất kỳ số lần nào:
    → Chọn một phần tử bất kỳ trong mảng và lật (flip) một bit trong biểu diễn nhị phân của nó (0 thành 1 hoặc 1 thành 0)

    Yêu cầu:
    → Tìm số lần lật bit tối thiểu để phép toán XOR của tất cả các phần tử trong mảng cuối cùng bằng k

    Ví dụ:
        Input: nums = [2, 1, 3, 4], k = 1
        1. Tính XOR hiện tại: 2 ^ 1 ^ 3 ^ 4 = (010)_2 ^ (001)_2 ^ (011)_2 ^ (100)_2 = (100)_2 = 4
        2. Mục tiêu là biến kết quả XOR này thành k = 1 (001)_2
        3. Để biến 4 (100) thành 1 (001), ta cần lật bit ở vị trí thứ 0 và vị trí thứ 2
        → Số thao tác: 2
        → Output: 2
*/

int minOperations(vector<int>& nums, int k){
    int temp = 0;
    for(int num : nums){
        temp ^= num;
    }

    int cnt = 0;
    while(temp != 0 || k != 0){
        if((temp & 1) != (k & 1)){
            cnt++;
        }
        temp >>= 1;
        k >>= 1;
    }

    return cnt;
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = minOperations(nums, k);
    cout << ans;
    return 0;
}