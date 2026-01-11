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
    LeetCode 945. Minimum Increment to Make Array Unique

    Đề bài:
    Cho một mảng số nguyên nums. Trong mỗi bước đi (move), bạn có thể chọn một chỉ số i và tăng giá trị nums[i] lên 1

    Yêu cầu:
    → Tìm số lượng bước đi tối thiểu để mọi giá trị trong mảng nums đều trở nên duy nhất

    Ví dụ:
        Input: nums = [1, 2, 2]
        → Có hai số 2. Ta tăng một số 2 lên thành 3
        → Mảng trở thành [1, 2, 3], các phần tử đã duy nhất
        → Số bước đi: 1
        → Output: 1

        Input: nums = [3, 2, 1, 2, 1, 7]
        → Sắp xếp lại: [1, 1, 2, 2, 3, 7]
        → Xử lý để duy nhất: [1, 2, 3, 4, 5, 7]
        → Số bước đi: (2-1) + (3-1) + (4-2) + (5-2) = 6
        → Output: 6
*/

int minIncrementForUnique(vector<int>& nums){
    sort(nums.begin(), nums.end());

    int ans = 0;
    int prev = nums[0];

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] <= prev){
            int need = prev + 1 - nums[i];
            ans += need;
            prev = prev + 1;
        } 
        else{
            prev = nums[i];
        }
    }

    return ans;
}


int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    int ans = minIncrementForUnique(nums);
    cout << ans;
    return 0;
}