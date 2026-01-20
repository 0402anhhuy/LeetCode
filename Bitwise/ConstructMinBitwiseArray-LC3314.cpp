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
    LeetCode 3314. Construct the Minimum Bitwise Array I

    Đề bài:
    Cho một mảng nums gồm n số nguyên là các số nguyên tố
    Bạn cần xây dựng một mảng ans có cùng độ dài sao cho với mỗi chỉ số i:
    → ans[i] OR (ans[i] + 1) == nums[i]

    Yêu cầu:
    1. Giá trị của mỗi ans[i] phải là nhỏ nhất có thể
    2. Nếu không tìm được giá trị ans[i] nào thỏa mãn điều kiện, đặt ans[i] = -1

    Ví dụ:
        Input: nums = [2, 3, 5, 7]
        → Với nums[0] = 2: Không có số nguyên không âm x nào để x OR (x+1) = 2. Trả về -1
        → Với nums[1] = 3: Nếu chọn ans[1] = 1, ta có 1 OR (1+1) = 1 OR 2 = 3. Thỏa mãn
        → Với nums[2] = 5: Nếu chọn ans[2] = 4, ta có 4 OR (4+1) = 4 OR 5 = 5. Thỏa mãn
        → Với nums[3] = 7: Có nhiều giá trị (ví dụ 3 hoặc 6), chọn giá trị nhỏ nhất là 3
        → Output: [-1, 1, 4, 3]
*/

vector<int> minBitwiseArray(vector<int>& nums){
    int n = nums.size();

    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= nums[i]; j++){
            if((j | (j + 1)) == nums[i]){
                ans[i] = j;
                break;
            }
        }
    }

    return ans;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<int> ans = minBitwiseArray(nums);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}