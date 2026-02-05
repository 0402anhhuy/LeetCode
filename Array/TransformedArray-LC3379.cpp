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
    LeetCode 3379. Transformed Array

    Đề bài:
    Cho một mảng số nguyên nums đóng vai trò là một mảng vòng (circular array). Bạn cần tạo một mảng mới result có cùng kích thước dựa trên các quy tắc sau:

    Quy tắc cho từng chỉ số i:
    1. Nếu nums[i] > 0: Bắt đầu từ vị trí i, di chuyển sang phải `nums[i]` bước. Gán `result[i]` bằng giá trị tại vị trí dừng lại
    2. Nếu nums[i] < 0: Bắt đầu từ vị trí i, di chuyển sang trái `abs(nums[i])` bước. Gán `result[i]` bằng giá trị tại vị trí dừng lại
    3. Nếu nums[i] == 0: Gán `result[i] = nums[i]`

    Lưu ý về mảng vòng:
    → Di chuyển quá phần tử cuối cùng sẽ quay lại đầu mảng
    → Di chuyển trước phần tử đầu tiên sẽ quay lại cuối mảng

    Ví dụ:
        Input: nums = [3, -2, 1, 1]
        - i=0, nums[0]=3: Từ index 0 đi phải 3 bước -> dừng ở index 3. result[0] = nums[3] = 1
        - i=1, nums[1]=-2: Từ index 1 đi trái 2 bước -> dừng ở index 3. result[1] = nums[3] = 1
        - i=2, nums[2]=1: Từ index 2 đi phải 1 bước -> dừng ở index 3. result[2] = nums[3] = 1
        - i=3, nums[3]=1: Từ index 3 đi phải 1 bước -> dừng ở index 0. result[3] = nums[0] = 3
        Output: [1, 1, 1, 3]
*/

vector<int> constructTransformedArray(vector<int>& nums){
    int n = nums.size();
    vector<int> result(n);

    for(int i = 0; i < n; i++){
        result[i] = nums[((i + nums[i]) % n + n) % n];
    }

    return result;
}

int main(){
    FAST_IO;

    int n; cin >> n;
    vector<int> nums(n);
    FORI(i, n) cin >> nums[i];

    vector<int> ans = constructTransformedArray(nums);
    FORI(i, ans.size()) cout << ans[i] << " ";
    return 0;
}