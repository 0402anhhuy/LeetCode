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
    LeetCode 3350. Adjacent Increasing Subarrays Detection II

    Đề bài:
    Cho một mảng số nguyên nums. Bạn cần tìm giá trị k lớn nhất sao cho tồn tại hai mảng con kề nhau, mỗi mảng có độ dài k, và cả hai đều tăng nghiêm ngặt

    Điều kiện:
    1. Mảng con 1: nums[a...a+k-1] tăng nghiêm ngặt
    2. Mảng con 2: nums[a+k...a+2k-1] tăng nghiêm ngặt
    3. Hai mảng này phải có cùng độ dài k và nằm sát nhau

    Yêu cầu:
    → Trả về giá trị k cực đại thỏa mãn điều kiện trên

    Ví dụ:
        Input: nums = [2, 5, 7, 8, 9, 2, 3, 4, 3, 1]
        → Các đoạn tăng dài nhất là: [2, 5, 7, 8, 9] (độ dài 5) và [2, 3, 4] (độ dài 3)
        → Nếu chọn k = 3: 
          Mảng con 1: [7, 8, 9] (tăng, dài 3)
          Mảng con 2: [2, 3, 4] (tăng, dài 3) -> Thỏa mãn kề nhau
        → Không có k = 4 nào thỏa mãn
        → Output: 3
*/

int maxIncreasingSubarrays(vector<int>& nums){
    vector<int> increments;

    int cnt = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i - 1]){
            cnt++;
        }
        else{
            increments.push_back(cnt);
            cnt = 1;
        }
    }

    increments.push_back(cnt);

    if(increments.size() == 1) return increments[0] / 2;

    int ans = 1;
    for(int i = 1; i < increments.size(); i++){
        ans = max(ans, min(increments[i], increments[i - 1]));
        ans = max({ans, increments[i] / 2, increments[i - 1] / 2});
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = maxIncreasingSubarrays(nums);
    cout << ans;
    return 0;
}