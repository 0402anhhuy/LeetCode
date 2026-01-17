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
    LeetCode 3349. Adjacent Increasing Subarrays Detection I

    Đề bài:
    Cho một mảng số nguyên nums độ dài n và một số nguyên k
    Bạn cần xác định xem có tồn tại hai mảng con nằm cạnh nhau, mỗi mảng có độ dài đúng bằng k, và cả hai đều tăng nghiêm ngặt (strictly increasing) hay không

    Điều kiện cụ thể:
    1. Mảng con thứ nhất xuất phát từ chỉ số a: nums[a...a+k-1] phải tăng nghiêm ngặt
    2. Mảng con thứ hai xuất phát từ chỉ số b: nums[b...b+k-1] phải tăng nghiêm ngặt
    3. Hai mảng con phải kề nhau: tức là chỉ số bắt đầu của mảng thứ hai phải ngay sau mảng thứ nhất (b = a + k)

    Yêu cầu:
    → Trả về true nếu tìm được cặp mảng con như vậy, ngược lại trả về false

    Ví dụ:
        Input: nums = [2, 5, 7, 8, 9, 2, 3, 4, 3, 1], k = 3
        → Xét a = 2: Mảng con 1 là [7, 8, 9] (tăng nghiêm ngặt, độ dài 3)
        → Xét b = a + k = 5: Mảng con 2 là [2, 3, 4] (tăng nghiêm ngặt, độ dài 3)
        → Hai mảng này kề nhau và đều tăng
        → Output: true
*/

bool hasIncreasingSubarrays(vector<int>& nums, int k){
    int n = nums.size();
    int cnt = 1, precnt = 0, ans = 0;

    for(int i = 1; i < n; ++i){
        if(nums[i] > nums[i - 1]){
            ++cnt;
        } 
        else{
            precnt = cnt;
            cnt = 1;
        }
        ans = max(ans, min(precnt, cnt));
        ans = max(ans, cnt / 2);
    }
    return ans >= k;
}

int main(){
    FAST_IO;

    int n, k; cin >> n >> k;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    cout << boolalpha << hasIncreasingSubarrays(nums, k);
    return 0;
}